#include <stdlib.h>
#include <stdio.h>

// /Users/YoungChanPark/projects/deepvariant/deepvariant/third_party/nucleus/testdata/test_reads.fastq

typedef struct {
	char header[200];
	char sequence[200];
	char optional[200];
	char quality[200];
} fastq_read;


int main (int argc, char *argv[]){
	FILE *fp;
	fastq_read read;
	// char line[200];
	// char *line_pointer = line;
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

	// puts(line);

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
