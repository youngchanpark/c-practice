#include <stdio.h>

/*
Ignore every third line of a file. 
*/


int main(int argc, char *argv[]) {
	FILE  *fp;
	int line_num = 1;
	char buffer[0x1000]; // hexadecimal of 4096

	fp = fopen(argv[1], "r"); // Read file and save to FILE pointer.


	printf("sizeof(buffer): %lu\n", sizeof(buffer));

	// Read line until end of file
	while (fgets(buffer, sizeof(buffer), fp) != NULL){
		if (line_num == 3){ // Condition to skip every 3rd line
			line_num = 0;
			continue;
		}

		printf("%i: %s", line_num, buffer); // Print line content;
		++line_num;
	}

	// Close file pointer
	fclose(fp);
}
