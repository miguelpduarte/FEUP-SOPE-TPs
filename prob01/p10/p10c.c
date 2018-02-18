#include <stdio.h>
#include <string.h>
//For isspace
#include <ctype.h>

//The maximum length of each command
#define MAX_COMMAND_LENGTH 256
//The maximum number of tokens of each command
#define MAX_COMMAND_TOKENS 25

//From: https://stackoverflow.com/questions/122616/how-do-i-trim-leading-trailing-whitespace-in-a-standard-way
char *trim_str(char *str) {
    size_t len = 0;
    char *frontp = str;
    char *endp = NULL;

    if(str == NULL) {
		return NULL;
	}
    if(str[0] == '\0') {
		return str;
	}

    len = strlen(str);
    endp = str + len;

    /* Move the front and back pointers to address the first non-whitespace
 	 * characters from each end.
	 */
    while(isspace((unsigned char) *frontp)) { ++frontp; }
    if(endp != frontp) {
        while(isspace((unsigned char) *(--endp)) && endp != frontp) {}
    }

    if(str + len - 1 != endp) {
        *(endp + 1) = '\0';
    } else if(frontp != str &&  endp == frontp) {
		*str = '\0';
	}

    /* Shift the string so that it starts at str so that if it's dynamically
     * allocated, we can still free it on the returned pointer.  Note the reuse
     * of endp to mean the front of the string buffer now.
     */
    endp = str;
    if(frontp != str) {
		while(*frontp) { *endp++ = *frontp++; }
		*endp = '\0';
    }


    return str;
}

int main() {
	//NOTE:
	//The exercise is not very clear, my interpretation is to just breakdown each "basic command" per line, basically spliting on ';' or '|'
	//Other interpretations may be possible but this was how I understood it


	printf("Insert the desired command: ");
	char command_input[MAX_COMMAND_LENGTH];
	fgets(command_input, MAX_COMMAND_LENGTH, stdin);

	char * current_str = NULL;
	//Used by strtok_r, to preserve data between calls via the arguments instead of internal variables, in order to be reentrant
	char * save_ptr = NULL;
	//Separating characters for strtok
	const char * separator_chars = "|;";

	//Array to store the strings
	char * command_arr[MAX_COMMAND_TOKENS];
	//The number of tokens passed into the command_arr, starts at 0, because it is empty
	int arr_length = 0;

	current_str = strtok_r(command_input, separator_chars, &save_ptr);

	if(current_str == NULL) {
		return 1;
	}
	
	//BIG NOTE FOR THE FUTURE:
	//strtok does not allocate new strings, it returns a pointer to a section of the original string (thus, it mangles up the original string)
	//keep this in mind because freeing the base original string would cause all the other strings to be dangling pointers, causing potential segfaults
	
	command_arr[arr_length] = current_str;
	arr_length++;

	while((current_str = strtok_r(NULL, separator_chars, &save_ptr)) != NULL) {
		command_arr[arr_length] = current_str;
		arr_length++;
	}

	printf("Split commands:\n");

	int i;
	for(i = 0; i < arr_length; ++i) {
		//a newline was used instead of a space for printing for easier verification
		printf("%sx\n", trim_str(command_arr[i]));
	}

	return 0;
}
