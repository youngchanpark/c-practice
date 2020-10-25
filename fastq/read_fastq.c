#include <stdlib.h>
#include <stdio.h>
#include "fastq.h"


/*
Reads a fastq file and prints out its content

Example
-------
$ ./a.out $example_file
*/

int main (int argc, char *argv[]){
	FILE *fp;
	fastq_read read; // This struct is in "fastq.h"
	// char line[200];
	// char *line_pointer = line;
	/*
	We dont do         = &line; because line variable
	 is an array of characters. So we just do = line; 
	 so that it points to the first value of the character array.
	*/

	// Argument parsing
	if (argc < 2 || argc > 2) {
		printf("Must give one argument.\n");
		exit(1);
	}


	printf("File: %s\n", argv[1]);
	fp = fopen(argv[1], "r");

	if (fp == NULL){
		printf("File does not exist.\n");
		exit(1);
	}

	// puts(line);
	// TODO: Change the while loop condition based on this Stack Overflow answer
	// https://stackoverflow.com/a/16108064
	while (feof(fp)==0){ 
		fgets(read.header, 200, fp);
		fgets(read.sequence, 200, fp);
		fgets(read.optional, 200, fp);
		fgets(read.quality, 200, fp);

		printf("header: %s", read.header);
		printf("sequence: %s", read.sequence);
		printf("optional: %s", read.optional);
		printf("quality: %s", read.quality);
	}

	fclose(fp);

	return 0;
}
