#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>


/**
 * Test to get the control of a terminal and to set process groups.
 * Minimalist shell-like interface is then provided.
 */

//#define TERMINAL_USED	"/dev/tty1"
#define TERMINAL_USED	"/dev/console"


// to allow to be tested even if input terminal is in raw mode
static int raw_gets(char *buf, int nb, int fd) {
	int i;

	i=0;
	while(i < nb-1) {
		int nbread;
		char c;

		if((nbread = read(fd, &c, 1)) < 0)
			break;

		if(nbread == 1) {
			if(c == '\n')
				break;
			buf[i] = c;
			i++;
		}
	}

	buf[i] = '\0';
	return i;
}

#define LINE_MAX	256


/**
 * Return the number of character in the current field (delimiters are '\0'
 * and ' ').
 */
static size_t current_field_size(const char *str) {
	int ret = 0;

	if(*str != '\0')
		for(ret=1; str[ret]!=' ' && str[ret]!='\0'; ret++);

	return ret;
}

int main(int argc, char **argv) {
	int fdin, fdout, fderr;
	char buf[LINE_MAX];

	fdin = open(TERMINAL_USED, O_RDONLY);
	fdout = open(TERMINAL_USED, O_WRONLY);
	fderr = open(TERMINAL_USED, O_WRONLY);


	printf("Trying to create a process group.\n");
	setpgid(0, 0);

	while(1) {
		int nbfields;
		char **all_args = NULL;
		char *buf_cur;

		printf("user@fixos# ");
		fflush(stdout);

		raw_gets(buf, 256, 0);

		// cut into program + arguments
		nbfields = 0;
		buf_cur = buf;
		while(*buf_cur != '\0') {
			buf_cur++;
			buf_cur += current_field_size(buf_cur);
			nbfields++;
		}

		if(nbfields > 0) {
			all_args = malloc(sizeof(*all_args) * nbfields);

			// copy each argument in an array (use buf to store strings)
			if(all_args != NULL) {
				int curfield;
				buf_cur = buf;
				for(curfield = 0; curfield < nbfields; curfield++) {
					all_args[curfield] = buf_cur;
					buf_cur += current_field_size(buf_cur);
					*buf_cur = '\0';
					buf_cur++;
				}
				all_args[curfield] = NULL;

				// now we can call execvp with all_args[0] as the file name
				pid_t pid;
				pid = fork();

				if(pid < 0) {
					printf("fork() error...\n");
				}
				else if(pid == 0) {
					// child, do execvp
					exit(execvp(all_args[0], all_args));
				}
				else {
					// father, should wait child
					pid_t wret;
					int status;
					wret = wait(&status);
					if(wret == pid) {
						// display a message depending the reason of wait return
						if(WIFEXITED(status)) {
							// if exited with 0, print nothing
							if(WEXITSTATUS(status) != 0)
								printf("> process end with status %d\n", WEXITSTATUS(status));
						}
						else if(WIFSIGNALED(status)) {
							printf("> process killed by signal %d\n", WTERMSIG(status));
						}
						else if(WIFSTOPPED(status)) {
							printf("> process %d stopped\n", wret);
						}
						else if(WIFCONTINUED(status)) {
							printf("> process %d continued\n", wret);
						}
						else {
							printf("> abnormal status : 0x%08X\n", status);
						}
					}
					else {
						printf("wait() for pid %d return %d!\n", pid, wret);
					}
				}	
			}
		}


	}	
}
