#include <stdio.h>

#define BUFFER_MAX 256

int main(int argc, char * argv[]) {
	if(argc != 3) {
		printf("Wrong number of arguments!\nUsage: %s <source> <destination>\n", argv[0]);
		return 1;
	}
	
	FILE *source;
	FILE *dest;

	//Opening the files
	//Source file in read mode
	source = fopen(argv[1], "r");
	if(source == NULL) {
		printf("Error opening source file!\n");
		return 2;
	}
	
	//Destination file in write mode
	dest = fopen(argv[2], "w");
	if(dest == NULL) {
		fclose(source);
		printf("Error opening destination file!\n");
		return 3;
	}

	size_t num_items_read;
	char buffer[BUFFER_MAX];
	
	//We are reading into the buffer, items of the size of each buffer element,
	//with the maximum of items being BUFFER_MAX, and reading from FILE* source
	//
	//fread also returns the number of items read (0 means EOF or error)
	//(Check fread(3) (aka fread's man page for more details) - like you always should in case of doubt)
	while ((num_items_read = fread(buffer, sizeof(*buffer), BUFFER_MAX, source)) > 0) {
		if(fwrite(buffer, sizeof(*buffer), num_items_read, dest) == 0) {
			printf("Error! Could not write to destination file!\n");
			fclose(source);
			fclose(dest);
			return -1;
		}
	}

	printf("Finished.\n");
	
	//Never forget to close files
	fclose(source);
	fclose(dest);	

	return 0;
}
