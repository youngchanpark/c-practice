#include <stdio.h>


int main(int argc, char *argv[]){
	FILE *fp;
	int line_count = 0; 
	// What if the file line count exceeds the integer limit?
	char buffer[0x1000];
	// What if a single line is greater than 4096 characters?
	fp = fopen(argv[1], "r");

	while (fgets(buffer, sizeof(buffer), fp) != NULL){
		++line_count;
	}

	printf("Line counter: %i\n", line_count);
	fclose(fp);

	return 0;
}
