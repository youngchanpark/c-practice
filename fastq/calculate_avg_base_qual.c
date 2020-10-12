#include <stdio.h>

char path[] = "/Users/YoungChanPark/projects/deepvariant/deepvariant/third_party/nucleus/testdata/test_reads.fastq";


int phred_score(char qual){
	return ((int) qual) - 33;
}

float calculate_mean(int *array, int n){
	float mean;
	int sum = 0, i;

	for (i = 0 ; i < n; i++){
		sum+=array[i];
	}
	mean = sum / (float)n;
	return mean;
}


int main(){
	FILE *fp;

	int line = 0, i;
	int array[200], fill = 0;
	char buffer[200], qual;

	fp = fopen(path, "r");

	while (fgets(buffer, sizeof(buffer), fp) != NULL){
		++line;
		if (line == 4){
			i = 0;
			qual = buffer[i];
			while (qual != '\n'){ // Change this to a do while loop
				array[fill] = phred_score(qual);
				++fill;
				++i;
				qual = buffer[i];
			}

			line = 0;
		}
	}

	printf("Mean: %f\n", calculate_mean(array, fill));
	fclose(fp);

	return 0;

}
