#include <stdio.h>
#include <stdlib.h>

void e_handler_1() {
	printf("Executing exit handler 1\n");
}

void e_handler_2() {
	printf("Executing exit handler 2\n");
}

void e_handler_3() {
	printf("Executing exit handler 3 which exits\n");
	exit(0);
}

int main() {
	if(atexit(e_handler_1) != 0) {
		printf("Error registering handler 1\n");
	}

	if(atexit(e_handler_2) != 0) {
		printf("Error registering handler 2\n");
	}
	
	if(atexit(e_handler_2) != 0) {
		printf("Error registering handler 2\n");
	}

	if(atexit(e_handler_3) != 0) {
		printf("Error registering handler 3\n");
	}

	if(atexit(e_handler_1) != 0) {
		printf("Error registering handler 1\n");
	}

	//abort();

	printf("Main done!\n");
	return 0;
}
