#include <stdio.h>
#include <dirent.h>

#include <unistd.h>
#include <fcntl.h>

#include <errno.h>

/**
 * ls-like program, using dirent.h POSIX API
 */

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

int main(int argc, char **argv) {
	int fdin, fdout, fderr;
	char path[256];

	fdin = open("/dev/console", O_RDONLY);
	fdout = open("/dev/console", O_WRONLY);
	fderr = open("/dev/console", O_WRONLY);

	if(fdin == -1 || fdout == -1 || fderr == -1) {
		return -1;
	}

	while(1) {
		DIR *dir;

		printf("Directory to scan? ");
		fflush(stdout);
	

		/*
		int i;
		while(fgets(path, 256, stdin) == NULL);
		for(i=0; path[i]!='\0' && path[i]!='\n'; i++);
		path[i] = '\0';
		*/

		raw_gets(path, 256, 0);

		dir = opendir(path);
		if(dir == NULL) {
			printf("error in opendir() : %d\n", errno);
		}
		else {
			// print each entry
			struct dirent *entry;
			
			while((entry = readdir(dir)) != NULL) {
				printf("%6d: %s\n", (int)entry->d_ino, entry->d_name);
			}
			closedir(dir);
		}
	}

	return 0;
}

