#include <stdio.h>


void change_int_value(int integer)
{
    printf("Inside change_int_value BEFORE: %i\n", integer);
    integer = 60;
    printf("Inside change_int_value AFTER: %i\n", integer);
}

void change_int_value_with_pointer(int *integer)
{
    printf("Inside change_int_value_with_pointer BEFORE: %p\n", integer);
    integer = 60; // Warning!
    // Because the argument is a pointer to integer
    // And I'm trying to assign an integer to a pointer to
    // integer.

    // So the actual value being saved here is a
    // hexadecimal of 60, which is 0x3c

    printf("Inside change_int_value_with_pointer AFTER: %p\n", integer);
}

void change_int_value_with_pointer_fixed(int *integer)
{
    *integer = 60; // Warning!
    // Because the argument is a pointer to integer
    // And I'm trying to assign an integer to a pointer to
    // integer
}

int main()
{
    int myint;
    int *int_pointer, *int_pointer2 = &myint;


    printf("Unspecified Pointer: %p\n", int_pointer);
    printf("Pointer to int variable with no init: %p\n", int_pointer2);
    // printf("Pointer deref: %i\n", *int_pointer); This Segfaults
    printf("Pointer2 deref: %i\n", *int_pointer2);

    myint = 100;
    printf("myint BEFORE: %i\n", myint);
    change_int_value(myint);
    printf("myint AFTER: %i\n", myint); // I'm expecting this not to change

    change_int_value_with_pointer(&myint);
    printf("myint AFTER AGAIN: %i\n", myint); // Still no change because of warning


    change_int_value_with_pointer_fixed(&myint);
    printf("myint AFTER AGAIN AGAIN: %i\n", myint); // Change expected
    return 0;

}
