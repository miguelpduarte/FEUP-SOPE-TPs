#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUF_MAX_SIZE 512

int main(int argc, char * argv[]) {
	if (argc != 2) {
		printf("Wrong no. of arguments.\nUsage: %s <file to write to>\n", argv[0]);
		return 1;
	}

	int output_file_desc = open(argv[1], O_WRONLY);
	if (output_file_desc == -1) {
		perror(argv[1]);
		return 2;
	}

	printf("Enter data in format \"<name> <score>\". EOF to exit\n");

	char name_arr[BUF_MAX_SIZE];
	int score;
	char output_buffer[BUF_MAX_SIZE + 6];
	
	while (scanf("%s %d", name_arr, &score) > 0) {
		sprintf(output_buffer, "%s %d", name_arr, score);
		write(output_file_desc, output_buffer, (strlen(output_buffer) + 0) * sizeof(*output_buffer));
		write(output_file_desc, "\n", 1);
	}

	close(output_file_desc);
	return 0;
}
