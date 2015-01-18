#include <stdio.h>

// needed for manually openning :
#include <unistd.h>
#include <fcntl.h>

/**
 * Simple stdio.h test, assuming no stdout/stdin/stderr are open
 */

#define write_const(fd, str) write((fd), (str), sizeof(str)-1)

int main(int argc, char **argv) {
	int fdin, fdout, fderr;

	fdin = open("/dev/console", O_RDONLY);
	fdout = open("/dev/console", O_WRONLY);
	fderr = open("/dev/console", O_WRONLY);

	if(fdin == -1 || fdout == -1 || fderr == -1) {
		return -1;
	}

	int number = 42;
	
	printf("Hello %s!\n"
			"We are using %s to print this message.\n"
			"%s value is %d, and its address is %p!\n",
		"World", "printf", "number", number, (void*)&number);


	printf("Now testing read() 5 times on fddin...\n");
	int i;
	char buf[256];

	for(i=0; i<5; i++) {
		int nbread = read(fdin, buf, 255);
		if(nbread < 0) {
			printf("Error on read()\n");
		}
		else {
			buf[nbread] = '\0';
			printf("From read(): %s\n", buf);
		}
	}

	printf("Now testing getc() 5 times...\n");
	for(i=0; i<5; i++) {
		char ob;
		ob = getc(stdin);
		printf("ASCII for character pressed : %d\n", ob);
	}

	while(1) {
		printf("Please enter a new value :\n");
		scanf("%d", &number);

		printf("dec=%d, hex=%X, hex=%08X\n", number, number, number);
	}

	return 0;
}

