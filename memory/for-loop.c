#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	int n, mycount;

	mycount = atoi(argv[1]);
	for ( n = 1;  n <= mycount;  ++n ){
		printf("count: %i\n", n);
	}

	return 0;
}
