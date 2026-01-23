#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_LEN 102

/*
	Author: Fernando Ruan
	Profile: https://codeforces.com/profile/fruan-ba
	Country: Brazil
	ChallengeLink: https://codeforces.com/problemset/problem/59/A
	I am happy to code :)
*/

static void printTheWord(char *str, bool *err) {
	int	smallLetters = 0;
	int	capitalLetters = 0;

	char *tmp = str;
	char digit;

	while (*tmp) {
		if (*tmp >= 'a' && *tmp <= 'z')
			++smallLetters;
		else if (*tmp >= 'A' && *tmp <= 'Z')
			++capitalLetters;
		else if (*tmp != '\n') {
			write(2, "Error\n", 6);
			*err = true;
			return ;
		}
		++tmp;
	}
	if (smallLetters >= capitalLetters) {
		while (*str) {
			if (*str >= 'a' && *str <= 'z') {
				digit = *str;
				write(1, &digit, 1);
			}
			else if (*str >= 'A' && *str <= 'Z') {
				digit = *str + 32;
				write(1, &digit, 1);
			}
			++str;
		}
	} else {
		while (*str) {
			if (*str >= 'a' && *str <= 'z') {
				digit = *str - 32;
				write(1, &digit, 1);
			}
			else if (*str >= 'A' && *str <= 'Z') {
				digit = *str;
				write(1, &digit, 1);
			}
			++str;
		}
	}
	return ;
}

int main (void) {
	char input[MAX_LEN];
	bool err = false;

	fgets(input, MAX_LEN, stdin);
	if (input[0] == '\n' || input[0] == '\0')
		return (0);
	printTheWord(input, &err);
	if (err)
		return (0);
	write(1, "\n", 1);
	return (0);
}
