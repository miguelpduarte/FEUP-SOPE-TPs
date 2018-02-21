#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 256

int main (int argc, char * argv[]) {
	if(argc != 2) {
		printf("Wrong no. of arguments!\nUsage: %s <source>\n", argv[0]);
		return 1;
	}

	int file_desc_1 = open(argv[1], O_RDONLY);
	if(file_desc_1 == -1) {
		perror(argv[1]);
		return 2;
	}

	ssize_t read_chars, written_chars;
	char buffer[BUFFER_SIZE];

	while((read_chars = read(file_desc_1, buffer, BUFFER_SIZE)) > 0) {
		if((written_chars = write(STDOUT_FILENO, buffer, read_chars)) <= 0 || read_chars != written_chars) {
			perror(argv[1]);
			close(file_desc_1);
			return 3;
		}
	}

	close(file_desc_1);
	return 0;
}
