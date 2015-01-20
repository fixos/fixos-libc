#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

#include <unistd.h>
#include <fcntl.h>

#include <errno.h>
#include <stdlib.h>
#include <string.h>

/**
 * ls-like program, using dirent.h and sys/stat.h POSIX API
 * Should be called within a compliant envirironment (fds 0, 1 and 2 should
 * be already open).
 * Should be called with argv[1] set to the path where to run ls.
 */

// print a file stat with a ls-like format
static void print_oneline_stat(const char *name, const struct stat *s) {
	// mode/type display (3*3 chars for mode and 1 char for type)
	char mode[11];
	switch(s->st_mode & S_IFMT) {
		case S_IFDIR:
			mode[0] = 'd'; break;
		case S_IFCHR:
			mode[0] = 'c'; break;
		case S_IFREG:
			mode[0] = '-'; break;
		default:
			mode[0] = '?';
	}
	mode[1] = s->st_mode & S_IRUSR ? 'r' : '-';
	mode[2] = s->st_mode & S_IWUSR ? 'w' : '-';
	mode[3] = s->st_mode & S_IXUSR ? 'x' : '-';

	mode[4] = s->st_mode & S_IRGRP ? 'r' : '-';
	mode[5] = s->st_mode & S_IWGRP ? 'w' : '-';
	mode[6] = s->st_mode & S_IXGRP ? 'x' : '-';

	mode[7] = s->st_mode & S_IROTH ? 'r' : '-';
	mode[8] = s->st_mode & S_IWOTH ? 'w' : '-';
	mode[9] = s->st_mode & S_IXOTH ? 'x' : '-';

	mode[10] = '\0';

	if((s->st_mode & S_IFMT) == S_IFCHR) {
		printf("%s %3d, %3d %s\n", mode, major(s->st_rdev), 
				minor(s->st_rdev), name);
	}
	else {
		printf("%s %8d %s\n", mode, s->st_size, name);
	}
}



int main(int argc, char **argv) {
	if(argc < 2) {
		fprintf(stderr, "usage : %s <path>\n", argc > 0 ? argv[0] : "ls");
		exit(1);
	}
	else {
		char *path = argv[1];

		DIR *dir;

		printf("Content of %s:\n", path);
		dir = opendir(path);
		if(dir == NULL) {
			printf("error in opendir() : %d\n", errno);
		}
		else {
			// print each entry
			struct dirent *entry;

			while((entry = readdir(dir)) != NULL) {
				struct stat statbuf;

				// not possible to avoid malloc without openat()!
				size_t pathlen = strlen(path);
				char *sfile = malloc(pathlen + strlen(entry->d_name)+2);
				strcpy(sfile, path);
				sfile[pathlen] = '/';
				strcpy(sfile + pathlen+1, entry->d_name);

				if(stat(sfile, &statbuf) == 0) {
					print_oneline_stat(entry->d_name, &statbuf);
				}
				else {
					printf("unable to stat '%s' (%d)\n", sfile, errno);
				}
					
				free(sfile);
			}
			closedir(dir);
		}
	}

	exit(0);
}

