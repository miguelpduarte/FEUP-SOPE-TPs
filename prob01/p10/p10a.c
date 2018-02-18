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
	
	//BIG NOTE FOR THE FUTURE:
	//strtok does not allocate new strings, it returns a pointer to a section of the original string (thus, it mangles up the original string)
	//keep this in mind because freeing the base original string would cause all the other strings to be dangling pointers, causing potential segfaults

	printf("%s", current_str);

	while((current_str = strtok_r(NULL, " ", &save_ptr)) != NULL) {
		printf(" %s", current_str);
	}

	return 0;
}
