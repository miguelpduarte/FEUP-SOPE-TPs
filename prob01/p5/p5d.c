#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	
	char * fullname = getenv("USER_NAME");
	if(fullname == NULL) {
		printf("Error: USER_NAME environment variable not set!\n");
		return 1;
	} else {
		printf("Hello %s !\n", fullname);
		return 0;
	}

}
