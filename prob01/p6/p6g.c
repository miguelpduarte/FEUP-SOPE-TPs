// PROGRAMA p6a.c

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define BUF_LENGTH 256

int main(int argc, char* argv[]) {

	if(argc != 3) {
		printf("Wrong number of arguments! Usage: %s <input file> <output file>\n", argv[0]);
		return -1;
	}
	
	FILE *src, *dst;
	char buf[BUF_LENGTH];

	if ((src = fopen(argv[1], "r")) == NULL) {
		printf("Could not open input file. errno is %d\n", errno);
		exit(1);
	}

	if ((dst = fopen(argv[2], "w")) == NULL) {
		printf("Could not open output file. errno is %d\n", errno);
		exit(2);
	}

	while(fgets(buf, BUF_LENGTH, src)) {
		fputs(buf, dst);
	}

	fclose(src);
	fclose(dst);
	exit(0); // zero é geralmente indicativo de "sucesso"
}
