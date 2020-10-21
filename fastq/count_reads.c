#include <stdio.h>

/*
Prints the number of reads in a fastq file.

Example
-------
$ ./a.out $example_file

*/

int main(int argc, char *argv[]){
	FILE *fp;
	unsigned short int line_counter = 0;
	int num_reads = 0;

	char buff[0x1000];

	fp = fopen(argv[1], "r");

	while (fgets(buff, sizeof(buff), fp) != NULL){
		++line_counter;

		if (line_counter == 4){
			line_counter = 0;
			++num_reads;
		}
	}

	printf("Number of reads: %i\n", num_reads);

	fclose(fp);

	return 0;
}
