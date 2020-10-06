#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	char static_string[] = "Hello"; 
	char *dynamic_string;
	int to_allocate;
	int *intPtr;
	printf("argc: %i\n", argc);

	printf("argv: %s\n", argv[0]);
	printf("argv[1]: %s\n", argv[1]);

	// to_allocate = (int) *argv[1];
	to_allocate = atoi(argv[1]);
	printf("to_allocate: %i\n", to_allocate);


	printf("static_string: %s\n", static_string);

	printf("dynamic_string: %s\n", dynamic_string);

	dynamic_string = (char *) malloc(to_allocate * sizeof(char));

	strcpy(dynamic_string, "HELLLLOOOOO");

	printf("dynamic_string: %s\n", dynamic_string);
	free(dynamic_string);
	printf("sizeof(char): %lu\n", sizeof(char));
	printf("sizeof(int): %lu\n", sizeof(to_allocate));


	printf("to_allocate * sizeof(char): %lu\n", to_allocate * sizeof(char));

	intPtr = (int*) malloc(1);
	intPtr[0] = 1;
	intPtr[1] = 20;
	intPtr[2] = 300;
	intPtr[3] = 400;
	intPtr[4] = 400;
	intPtr[5] = 400;
	intPtr[6] = 400;
	intPtr[7] = 400;

	printf("malloc: %p\n", malloc(8));
	printf("malloc int: %i\n", intPtr[0]);
	printf("malloc int: %i\n", intPtr[1]);
	printf("malloc int: %i\n", intPtr[2]);
	printf("malloc int: %i\n", intPtr[3]);
	printf("malloc int: %i\n", intPtr[4]);
	printf("malloc int: %i\n", intPtr[5]);
	printf("malloc int: %i\n", intPtr[6]);
	printf("malloc int: %i\n", intPtr[7]);
	printf("malloc int: %p\n", intPtr);
	
	free(&intPtr[0]);
	return 0;
}
