#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>


int main(int argc, char *argv[])
{
	uint8_t before_shift = 0b00001000; // 8
	printf("Before: %" PRIu8 "\n", before_shift);
	uint8_t after_shift = before_shift >> 3; 
	// Expected to be 0b00000001
	
	printf("After: %" PRIu8 "\n", after_shift); // 1
	
	return 0;
}
