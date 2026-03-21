#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>

#define MAX_LEN 102

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/122/A
        I am happy to code :)
*/

static long long numberConversor(char *n, bool *err) {
	long long result = 0;
	long long signal = 1;

	while (*n == ' ' || *n == '\t' || *n == '\n' || *n == '\f' || *n == '\v'
		|| *n == '\a' || *n == '\b')
		++n;
	while (*n == '+' || *n == '-') {
		if (*n == '-')
			signal *= -1;
		++n;
	}
	while (*n >= '0' && *n <= '9') {
		result *= 10;
		result += *n - '0';
		if (result > INT_MAX || (result * signal) < INT_MIN) {
			*err = true;
			return (0);
		}
		++n;
	}
	return (result * signal);
}

static bool hasLuckyNumbers(char *input) {

	bool hasFour = false;
	bool hasSeven = false;

	while (*input != '\n' && *input != '\0') {
		if (*input == '4' && !hasFour)
			hasFour = true;
		else if (*input == '7' && !hasSeven)
			hasSeven = true;
		else
			return (false);
		if (hasFour && hasSeven) {
			write(1, "YES\n", 4);
			return (true);
		}
		++input;
	}
	return (false);
}
int main(void) {
	char input[MAX_LEN];

	fgets(input, MAX_LEN, stdin);

	if (input[0] == '\0' || input[0] == '\n')
		return (0);

	bool err = false;

	long long number = numberConversor(input, &err);

	if (err)
		return (0);

	if (hasLuckyNumbers(input)) 
		return (0);

	if (number % 4 == 0 || number % 7 == 0 || number % 47 == 0 || number % 74 == 0 || number % 447 == 0
		|| number % 477 == 0 || number % 744 == 0) {
		write(1, "YES\n", 4);
		return (0);
	} else
		write(1, "NO\n", 3);
	return (0);
}
