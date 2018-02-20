#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_MAX 256

int main(int argc, char * argv[]) {
	if(argc != 3) {
		//printf source destinaton
		return 1;
	}
	
	int source_fd, dest_fd;

	//Opening the files
	source_fd = open(argv[1], O_RDONLY);
	if(source_fd == -1) {
		printf("Error opening source file!\n");
		return 2;
	}
	

	dest_fd = open(argv[2], O_WRONLY);
	if(dest_fd == -1) {
		close(source_fd);
		printf("Error opening destination file!\n");
		return 3;
	}

	ssize_t num_chars_read;
	char buffer[BUFFER_MAX];

	while ((num_chars_read = read(source_fd, buffer, BUFFER_MAX)) > 0) {
		write(dest_fd, buffer, num_chars_read);
	}

	printf("Finished.\n");
	
	close(source_fd);
	close(dest_fd);

	return 0;
}
