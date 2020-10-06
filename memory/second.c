#include <stdio.h>
#include <stdlib.h>
// https://www.codingunit.com/c-tutorial-the-functions-malloc-and-free


int main(int argc, char* argv[])
{
	int *ptr_one;

	
	ptr_one = (int *)malloc(atoi(argv[1]) * sizeof(int));

	if (ptr_one == 0)
	{
		printf("ERROR: Out of memory\n");
		return 1;
	}

	*ptr_one = 25;
	printf("%d\n", *ptr_one);

	free(ptr_one);

	return 0;
}
