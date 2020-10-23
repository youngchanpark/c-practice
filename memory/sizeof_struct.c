#include <stdio.h>

typedef struct {
	char first;
} MyChar;

typedef struct {
	int first;
} MyInt;

typedef struct {
	char first;
	int second;
} Both;



int main(){
	MyChar mychar;
	MyInt myint;
	Both both;


	printf("sizeof(mychar): %lu\n", sizeof(mychar));
	printf("sizeof(myint): %lu\n", sizeof(myint));
	printf("sizeof(both): %lu\n", sizeof(both));
}
