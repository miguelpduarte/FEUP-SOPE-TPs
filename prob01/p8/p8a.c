#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
	if(argc != 3) {
		printf("Invalid no. of arguments! Usage: %s <n1> <n2>\n", argv[0]);
		return 1;
	}
	
	//Lazy conversion of string to ints, should use strtol and check for errors instead
	int n1 = atoi(argv[1]);
	int n2 = atoi(argv[2]);

	if(n2 >= n1) {
		printf("n2 can't be greater than or equal to n1!\n");
		return 2;
	}
	
	//Gives the random number generator a different seed each time
	srand(time(NULL));
	
	int i = 0;
	//Just ensuring that gen_num is different than n2 starting out, to not hit the termination condition
	int gen_num = n2 - 1;
	for( ; gen_num != n2 ; ++i) {
		//Since rand returns a number between 0 and RAND_MAX, we need only "confine" the number to the desired interval
		
		gen_num = rand() % n1;
		printf("i: %4d\tval: %4d\n", i, gen_num);
	}

	return 0;
}
