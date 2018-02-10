#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[], char* env[]) {
	for(; *env != NULL; ++env) {
		if(strncmp(*env, "USER=", strlen("USER=")) == 0) {
			//Substring is shifting the string base address by a value
			printf("Hello %s !\n", *env + strlen("USER="));
			return 0;
		}
	}

	printf("Error: USER environment variable not set!\n");
	return 1;
}
