#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUF_MAX_SIZE 512

typedef struct {
	char name[BUF_MAX_SIZE];
	int score;
} student_record;

int main(int argc, char * argv[]) {
	if (argc != 2) {
		printf("Wrong no. of arguments.\nUsage: %s <file to read from>\n", argv[0]);
		return 1;
	}

	int input_file_desc = open(argv[1], O_RDONLY);
	if (input_file_desc == -1) {
		perror(argv[1]);
		return 2;
	}

	student_record sr;
	
	while (read(input_file_desc, &sr, sizeof(sr)) > 0) {
		printf("Name: %s Score: %d\n", sr.name, sr.score);
	}

	close(input_file_desc);
	return 0;
}
