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

	i = 0;
	while( environ[i] != NULL )
	{
		if( memcmp(name, environ[i], name_length) == 0
				&& environ[i][name_length] == '=')
		{
			break;
		}
		i++;
	}
	// If we didn't found the string, create it.
	if( environ[i] == NULL )
	{

		// Creating the new environ (+2 because previous and new NULL)
		char **new_environ;
			new_environ = malloc((i + 2) * sizeof(char *));
			if(new_environ != NULL) {
				memcpy(new_environ, environ, (i + 1) * sizeof(char*));
				// free(environ);
			}

		if(new_environ == NULL)
			return -1;

		// Replacing the environ for new one.
		for( int j = 0 ; j <= i; j++ )
		{
			new_environ[j] = environ[j];
		}
		new_environ[i + 1] = NULL;
		free(environ);
		environ = new_environ;
	}
	// We found the variable
	else if ( overwrite == 0 )
		// We can't change it
		return 0;

	// Allocating the new variable
	char *new_var = (char *) malloc((name_length + value_length + 2) * sizeof(char));
	if( new_var == NULL )
	{
		errno = ENOMEM;
		return -1;
	}
	// Setting the new variable
	memcpy(new_var, name, name_length);
	new_var[name_length] = '=';
	memcpy(&new_var[name_length + 1], value, value_length);
	new_var[name_length + value_length + 1] = '\0';
	environ[i] = new_var;

	return 0;
}
