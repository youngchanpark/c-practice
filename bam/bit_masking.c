#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

/*
Writing raw binary format in C
https://www.includehelp.com/c/how-to-assign-binary-value-in-a-variable-directly.aspx

Printing binary pattern of variable value
https://stackoverflow.com/a/3208376
*/


int main (int argc, char *argv[]){
	uint8_t uint8_value = 0b10101010;
	uint8_t higher_bit_mask = 0b11110000;
	uint8_t lower_bit_mask = 0b00001111;
	uint16_t uint16_value = 0b1111111111111111; // Decimal = 65535

	printf("uint8_value: "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(uint8_value));
	printf("uint8_value & higher_bit_mask: "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(uint8_value & higher_bit_mask));
	printf("uint8_value & lower_bit_mask: "BYTE_TO_BINARY_PATTERN"\n", BYTE_TO_BINARY(uint8_value & lower_bit_mask));
	
	// Defined macros only works for 8-bit values :(
	/* Using an 8-bit mask on 16-bit value works! */
	printf("uint16_value: %"PRIu16"\n", uint16_value);
	// printf("uint16_value & higher_bit_mask: %"PRIu16"\n", (uint16_value & higher_bit_mask)); // Generated warning
	printf("uint16_value & higher_bit_mask: %i\n", (uint16_value & higher_bit_mask));
	/* Above print outputs 240.
	
	Explanation
	Value : 1111111111111111
	Mask  :         11110000
	Out   : 0000000011110000 == 240 
	*/

	return 0;
}
