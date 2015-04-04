#include <errno.h>
#include <string.h>
#include <stdlib.h>

int setenv(const char *name, const char *value, int overwrite) {
	int name_length = strlen(name);
	int value_length = strlen(value);
	int i;


	if( environ == NULL || name_length == 0 || strrchr(name, '=') != NULL) {
		errno = EINVAL;
		return -1;
	}

	for(i=0; environ[i] != NULL; i++) {
		if( memcmp(name, environ[i], name_length) == 0
				&& environ[i][name_length] == '=')
		{
			break;
		}
	}
	// If we didn't found the string, create it.
	if( environ[i] == NULL )
	{

		// Creating the new environ (+2 because previous and new NULL)
		char **new_environ;
		// first allocation, use malloc (environ is set to stack) and copy
		new_environ = malloc((i+2) * sizeof(char *));
		if(new_environ != NULL) {
			memcpy(new_environ, environ, (i + 1) * sizeof(char*));
		}

		if(new_environ == NULL)
			return -1;

		new_environ[i + 1] = NULL;
		environ = new_environ;
	}
	// We found the variable
	else if ( overwrite == 0 )
		// We can't change it
		return 0;

	// Allocating the new variable (we can't free the old...)
	// TODO optimize to avoid re-allocating if old string was larger
	char *new_var = malloc((name_length + value_length + 2) * sizeof(char));
	if( new_var == NULL )
		return -1;

	// Setting the new variable
	memcpy(new_var, name, name_length);
	new_var[name_length] = '=';
	memcpy(&new_var[name_length + 1], value, value_length + 1);
	environ[i] = new_var;

	return 0;
}
