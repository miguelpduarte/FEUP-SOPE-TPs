#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	
	char * username = getenv("USER");
	if(username == NULL) {
		printf("Error: USER environment variable not set!\n");
		return 1;
	} else {
		printf("Hello %s !\n", username);
		return 0;
	}

}
