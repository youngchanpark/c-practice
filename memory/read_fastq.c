#include <stdlib.h>
#include <stdio.h>

// /Users/YoungChanPark/projects/deepvariant/deepvariant/third_party/nucleus/testdata/test_reads.fastq


int main (int argc, char *argv[]){
	FILE *fp;
	char line[200];
	char *line_pointer = line;
	/*
	We dont do         = &line; because line variable
	 is an array of characters. So we just do = line; 
	 so that it points to the first value of the character array.
	*/

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

	fgets(line_pointer, 200, fp);
	// puts(line);
	printf("Line: %s", line);


	fclose(fp);

	return 0;
}
