#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 256

int main (int argc, char * argv[]) {
	if(argc != 2 && argc != 3) {
		printf("Wrong no. of arguments!\nUsage: %s <source> [<destination>]\n", argv[0]);
		return 1;
	}


	int file_desc_1;
	int file_desc_2;

	file_desc_1 = open(argv[1], O_RDONLY);
	if(file_desc_1 == -1) {
		perror(argv[1]);
		return 2;
	}

	if(argc == 3) {
		// If copying from source to destination, open destination and redirect STDOUT to it
		//
		//Creation permissions: rw- rw- r--
		file_desc_2 = open(argv[2], O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);	
	
		//Checking for opening errors
		if(file_desc_2 == -1) {
			perror(argv[2]);
			close(file_desc_1);
			return 3;
		}

		//Redirecting STDOUT
		if(dup2(file_desc_2, STDOUT_FILENO) == -1) {
			perror("Could not redirect input using 'dup2': ");
			close(file_desc_2);
			close(file_desc_1);
		}
	}

	ssize_t read_chars, written_chars;
	char buffer[BUFFER_SIZE];

	while((read_chars = read(file_desc_1, buffer, BUFFER_SIZE)) > 0) {
		if((written_chars = write(STDOUT_FILENO, buffer, read_chars)) <= 0 || read_chars != written_chars) {
			perror(argv[1]);
			close(file_desc_1);
			if(argc == 3) {
				close(file_desc_2);
			}
			return 3;
		}
	}

	close(file_desc_1);
	if(argc == 3) {
		close(file_desc_2);
	}
	return 0;
}
