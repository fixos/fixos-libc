#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include <errno.h>
#include <stdlib.h>

int execlp(const char *path, const char *arg0, ...) {
	char **array;
	va_list va;
	int nb = 1;

	// first traversal to compute the number of args
	va_start(va, arg0);
	while(va_arg(va, const char*) != NULL)
		nb++;
	va_end(va);

	array = malloc(sizeof(*array) * nb);
	if(array == NULL) {
		errno = ENOMEM;
		return -1;
	}

	// second traversal (copy values)
	array[0] = (char*)arg0;
	nb = 1;
	va_start(va, arg0);
	while(NULL != (array[nb++] = va_arg(va, char*)) );
	va_end(va);
	
	int ret;
	ret = execvpe(path, array, environ);

	// error: execve should not return
	free(array);
	return ret;
}


