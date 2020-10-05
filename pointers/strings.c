#include <stdio.h>

char * return_char_pointer()
{
	char result[10] = "Returned";
	printf("result: %s\n", result);
	char *result_pointer = result;
	return result_pointer;
}

int main()
{
	char single_char, char_array_not_used[11];
	char char_array[11] = "Hello World";
	char char_array_short[5] = "Hello World"; // This will generate a warning
	char *char_pointer, *array_pointer;
	char *from_func;
	
	single_char = 'A';

	// You can initialise strings,
	// but cannot assign strings like below. 
	// char_array = "Hello World";

	printf("single_char: %c\n", single_char);
	printf("char_array: %s\n", char_array);
	printf("char_array_short: %s\n", char_array_short);

	printf("char_pointer: %p\n", char_pointer);
	printf("array_pointer: %p\n", array_pointer);

	from_func = return_char_pointer();
	printf("from_func: %c, %p\n", *from_func, from_func);
	printf("from_func[1]: %c\n", *(from_func+1));
	return 0;
}
