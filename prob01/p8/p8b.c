#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(int argc, char *argv[]) {
	//For real time
	struct timespec start_rt, end_rt;
	//Start real time
	clock_gettime(CLOCK_REALTIME, &start_rt);
	//For CPU time in user and system mode
	struct rusage usage;
	struct timeval systime_start, systime_end;
	struct timeval usrtime_start, usrtime_end;
	
	//Getting current usage
	getrusage(RUSAGE_SELF, &usage);
	//Start time system and user mode
	systime_start = usage.ru_stime;
	usrtime_start = usage.ru_utime;
	
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

	//End of real time
	clock_gettime(CLOCK_REALTIME, &end_rt);
	
	//Getting current usage
	getrusage(RUSAGE_SELF, &usage);
	//End time system and user mode
	systime_end = usage.ru_stime;
	usrtime_end = usage.ru_utime;

	printf("Real time elapsed (ms): %f\n", (end_rt.tv_sec - start_rt.tv_sec) * 1000.0 + (end_rt.tv_nsec - start_rt.tv_nsec) / 1000000.0);
	printf("CPU time in system mode (ms): %f\n", (systime_end.tv_sec - systime_start.tv_sec) * 1000.0 + (systime_end.tv_usec - systime_start.tv_usec) / 1000.0);
	printf("CPU time in user mode (ms): %f\n", (usrtime_end.tv_sec - usrtime_start.tv_sec) * 1000.0 + (usrtime_end.tv_usec - usrtime_start.tv_usec) / 1000.0);

	return 0;
}
