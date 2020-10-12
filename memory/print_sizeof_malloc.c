#include <stdio.h>
#include <stdlib.h>
/*

Keep reading in (int) argv[1] amount of characters
and printing it with a "-----" prefix until the end of the
file content.

$ ./a.out 20 $example_file
*/

int main(int argc, char *argv[]){
	FILE *fp;
	int to_allocate;
	char *num_chars;
	
	
	to_allocate = atoi(argv[1]);
	num_chars = (char *) malloc(to_allocate);

	printf("to_allocate: %i\n", to_allocate);
	printf("sizeof(num_chars): %lu\n\n", sizeof(num_chars)); // Deceiving
	/*
	sizeof(num_chars) doesn't actually return the number of characters 
	storable in num_chars string array, but the number of bytes needed
	to store a pointer variable!
	Our machine is a 64bit architecture, so 8 bytes (8bits = 1 byte, so 64bits = 8 bytes)
	Reference: https://youtu.be/P0k1C3F61xY
	*/ 
	
	fp = fopen(argv[2], "r");

	while (fgets(num_chars, to_allocate, fp) != NULL){
		/*
		fgets function stores to_allocate-1 characters to the pointer num_chars.
		Therefore, you'll notice that it only print 19 characters to num_chars
		if you run the executable with 20 as its first parameter argument.
		*/
		printf("-----%s", num_chars);

	}
	printf("End\n");
	free(num_chars); // Let's not forget to return the allocated memory!
	fclose(fp); // And also to not forget to close the file pointer!

	return 0;
}
