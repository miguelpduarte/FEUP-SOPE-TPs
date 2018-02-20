#include <termios.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define MAX_PW_LENGTH 64

int main() {

	struct termios old_term, term;

	char pw[MAX_PW_LENGTH];
	char echo[]  = "*";
	char read_char;

	//Requesting user input
	write(STDOUT_FILENO, "\nPassword? ", strlen("\nPassword? ") * sizeof(char));

	//Reading STDIN attributes
	tcgetattr(STDIN_FILENO, &old_term);
	term = old_term;

	//Altering STDIN attributes
	term.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);

	int writeIndex = 0;
	while(writeIndex < MAX_PW_LENGTH && read(STDIN_FILENO, &read_char, 1) && read_char != '\n') {
		pw[writeIndex++] = read_char;
		write(STDOUT_FILENO, &echo, strlen(echo) * sizeof(char));
	}
	pw[writeIndex] = '\0';

	tcsetattr(STDIN_FILENO, TCSANOW, &old_term);
	write(STDOUT_FILENO, "\n\nPassword: ", 12);
 	write(STDOUT_FILENO, pw, strlen(pw));
 	write(STDOUT_FILENO, "\n", 1);

	char numstr[12];
	sprintf(numstr, "%i", writeIndex);

	write(STDOUT_FILENO, "Value of 'i': ", strlen("Value of 'i': "));
	write(STDOUT_FILENO, numstr, strlen(numstr));
	write(STDOUT_FILENO, "\n", 1);
	
	return 0;
}
