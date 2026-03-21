#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_LEN 102

/*
	Author: Fernando Ruan
	Profile: https://codeforces.com/profile/fruan-ba
	Country: Brazil
	ChallengeLink: https://codeforces.com/problemset/problem/133/A
	I am happy to code :)
*/

static bool checkInput(char *input) {
	while (*input) {
		if (*input == 'H' || *input == 'Q' || *input == '9')
			return (true);
		++input;
	}
	return (false);
}

int main(void) {
	char input[MAX_LEN];

	fgets(input, MAX_LEN, stdin);
	if (input[0] == '\0' || input[0] == '\n')
		return (0);
	if (checkInput(input))
		write(1, "YES\n", 4);
	else
		write(1, "NO\n", 3);
	return (0);
}
