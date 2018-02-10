#include <stdio.h>

int main(int argc, char* argv[], char* env[]) {
	for(; *env != NULL; ++env) {
		printf("%s\n", *env);
	}

	return 0;
}
