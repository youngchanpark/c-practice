#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[])
{
	int num, end;

	end = atoi(argv[1]);

	while (num < end){
		printf("num: %i\n", num);
		++num;
	}
	
	return 0;
}



