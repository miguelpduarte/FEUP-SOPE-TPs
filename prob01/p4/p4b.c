#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Arguments should be in the format <name> <number of times>
int main(int argc, char* argv[]) {
	//Considering names that have no more than 25 characters (Used just as an arbitrary example, could be more)
	const int MAX_CHAR_PER_NAME = 25;

	//Creating the string that will hold the full name
	//We can use a char[] because this does not need to persist, so no allocation is needed
	//The string can hold argc - 2 names + argc - 2 spaces + the null terminator
	char full_name[MAX_CHAR_PER_NAME * (argc - 2) + (argc - 2) + 1];
	//Ensuring that if no names were passed, the string does not serve as an access to random memory
	full_name[0] = '\0';

	int i = 1;
	//There is no problem in there not being a name, since 1 < 1 is false and thus no further arguments will be read
	//Thus, the program does not crash on null arguments
	for(; i < argc - 1; ++i) {
		//Just in case the passed string is larger than the maximum characters per name
		if(strlen(argv[i]) > MAX_CHAR_PER_NAME) {
			return 1;
		}

		//Concatenating the passed names with spaces at the end
		strncat(full_name, argv[i], MAX_CHAR_PER_NAME);
		strncat(full_name, " ", 1);
	}

	//Parsing the last argument (number of times to repeat the name)
	//Not error checking because of laziness, should use strtol and check for errors
	int n_times = atoi(argv[argc - 1]);

	//Printing the complete salutation n_times times
	for(i = 0; i < n_times; ++i) {
		printf("Hello %s!\n", full_name);
	}

	return 0;
}
