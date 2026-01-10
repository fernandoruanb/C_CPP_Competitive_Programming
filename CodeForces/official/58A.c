#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_LEN 1000

/*
	Author: Fernando Ruan
	Profile: https://codeforces.com/profile/fruan-ba
	Country: Brazil
	ChallengeLink: https://codeforces.com/problemset/problem/58/A
	I am happy to code :)
*/

// to check the match

static bool check_hello(char *str) {
	char *target = "hello";
	int index = 0;

	while (*str) {
		if (*str == target[index] || *str == target[index] - 32)
			++index;
		++str;
	}
	if (index == 5)
		return (true);
	return (false);
}

int main (void) {
	char str[MAX_LEN];

	fgets(str, MAX_LEN, stdin);
	if (!str) {
		write(2, "Input Error\n", 13);
		return (-1);
	}
	if (!check_hello(str))
		write(1, "NO\n", 3);
	else
		write(1, "YES\n", 4);
	return (0);
}
