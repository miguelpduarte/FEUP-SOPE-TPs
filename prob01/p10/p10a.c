#include <stdio.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 256

int main() {
	printf("Insert the desired command: ");
	char command_input[MAX_COMMAND_LENGTH];
	fgets(command_input, MAX_COMMAND_LENGTH, stdin);

	char * current_str = NULL;
	//Used by strtok_r, to preserve data between calls via the arguments instead of internal variables, in order to be reentrant
	char * save_ptr = NULL;

	current_str = strtok_r(command_input, " ", &save_ptr);

	if(current_str == NULL) {
		printf("%s", command_input);
		return 0;
	}
	
	printf("%s", current_str);

	while((current_str = strtok_r(NULL, " ", &save_ptr)) != NULL) {
		printf(" %s", current_str);
	}

	return 0;
}
