#include <stdio.h>
#include <zlib.h>

/*
Open a gzipped file using the zlib library and print each line.
*/

// https://stackoverflow.com/a/35093152
int main(int argc, char *argv[]){

	gzFile fp;
	char buff[1024];

	fp = gzopen(argv[1], "rb");

	while (gzgets(fp, buff, sizeof(buff)) != NULL){
		printf("%s", buff);
	}

	printf("EOF\n");

	gzclose(fp);

	return 0;
}
