#include <stdio.h>
#include <stdlib.h>

// /Users/YoungChanPark/projects/deepvariant/deepvariant/third_party/nucleus/testdata/test_reads.fastq
int main (int argc, char *argv[]){
	FILE* fp;
	int line = 1;
	char array[200];
	int quals[200];

	fp = fopen(argv[1], "r");

	while (line != 4){
		fgets(array, 200, fp);
		++line;
	}

	fgets(array, 200, fp);

	printf("%s", array);


	size_t i = 0;
	for (i = 0; i < sizeof(array) ; ++i){
		if (array[i] == '\0' || array[i] == '\n'){ // Newline character is also saved
			printf("Break\n");
			break;
		}
		quals[i] = ((int) array[i]) - 32; // Typecast then minus 32
	}
	
	for (i = 0; i < sizeof(array) ; ++i){
		if (array[i] == '\0' || array[i] == '\n'){
			printf("Break\n");
			break;
		}
		printf("%c: %i\n", array[i], quals[i]);
	}
	

	return 0;
}
