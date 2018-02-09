#include <stdio.h>

int main(int argc, char* argv[]) {
	printf("Hello ");
	
	int i = 1;
	//There is no problem in there not being a name, since 1 < 1 is false and thus no further arguments will be read
	//Thus, the program does not crash on null arguments
	for(; i < argc; ++i) {
		printf("%s ", argv[i]);
	}

	printf("!\n");
	return 0;
}
