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
		printf("Wrong no. of arguments.\nUsage: %s <file to write to>\n", argv[0]);
		return 1;
	}

	int output_file_desc = open(argv[1], O_WRONLY);
	if (output_file_desc == -1) {
		perror(argv[1]);
		return 2;
	}

	printf("Enter data in format \"<name> <score>\". EOF to exit\n");

	student_record sr;
	
	//Should use fgets to get the name, this only accepts names with only one word, but this is not the point of the exercise 
	while (scanf("%s %d", sr.name, &(sr.score)) > 0) {
		write(output_file_desc, &sr, sizeof(sr));
	}

	close(output_file_desc);
	return 0;
}
