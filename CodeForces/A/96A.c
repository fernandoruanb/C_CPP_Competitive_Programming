#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_LEN 102

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/96/A
        I am happy to code :)
*/

static void checkDanger(char *input, bool *err) {
	int	x = 0;
	int	y = 0;

	while (*input) {
		if (*(input + 1) == '\0' && x >= 7 || y >= 7) {
			*err = true;
			return ;
		}
		if (*input == '1' && y >= 7) {
			*err = true;
			return ;
		} else if (*input == '0' && x >= 7) {
			*err = true;
			return ;
		}
		if (*input == '1') {
			++x;
			y = 0;
		}
		else if (*input == '0') {
			++y;
			x = 0;
		}
		++input;
	}
}

int main(void) {
	char input[MAX_LEN];
	bool err = false;

	fgets(input, MAX_LEN, stdin);
	if (input[0] == '\n' || input[0] == '\0') {
		write(2, "Error\n", 6);
		return (0);
	}
	checkDanger(input, &err);
	if (err)
		write(1, "YES\n", 4);
	else
		write(1, "NO\n", 3);
	return (0);
}
