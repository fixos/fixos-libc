#include <dirent.h>
#include <fcntl.h>

#include <stddef.h>


DIR *opendir(const char *name) {
	int fd;
	
	fd= open(name, O_RDONLY);
	if(fd == -1) {
		return NULL;
	}
	return fdopendir(fd);
}
