#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_LEN 10002

/*
	HACKERRANK CHALLENGES JOURNEY!!!

	Author: Fernando Ruan
	Country: Brazil
	Challenge: https://www.hackerrank.com/challenges/frequency-of-digits-1/problem?isFullScreen=true
	I am happy to code :)
*/

static void countNumbersAndPrint(char *input) {
	int zero = 0;
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	int six = 0;
	int seven = 0;
	int eight = 0;
	int nine = 0;

	while (*input) {
		switch (*input) {
			case '0':
				zero++;
				break ;
			case '1':
				one++;
				break ;
			case '2':
				two++;
				break ;
			case '3':
				three++;
				break ;
			case '4':
				four++;
				break ;
			case '5':
				five++;
				break ;
			case '6':
				six++;
				break ;
			case '7':
				seven++;
				break ;
			case '8':
				eight++;
				break ;
			case '9':
				nine++;
		}
		++input;
	}
	printf("%d %d %d %d %d %d %d %d %d %d\n", zero, one, two, three, four, five, six, seven, eight, nine);
}

int main (void) {
	char input[MAX_LEN];
	struct counter;

	fgets(input, MAX_LEN, stdin);
	if (input[0] == '\0' || input[0] == '\n')
		return (0);
	countNumbersAndPrint(input);
	return (0);
}
