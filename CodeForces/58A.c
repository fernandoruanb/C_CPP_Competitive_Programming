#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

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
		if (index == 4)
			return (true);
		if (*str == target[index] || *str == target[index] - 32)
			++index;
		++str;
	}
	return (false);
}

int main (int argc, char **argv) {
	if (argc < 2) {
		write(2, "Missed input\n", 13);
		return (-1);
	}
	if (!check_hello(argv[1]))
		write(1, "NO\n", 3);
	else
		write(1, "YES\n", 4);
	return (0);
}
