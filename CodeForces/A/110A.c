#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*
	Author: Fernando Ruan
	Profile: https://codeforces.com/profile/fruan-ba
	Country: Brazil
	ChallengeLink: https://codeforces.com/problemset/problem/110/A
	I am happy to code :)
*/

/*static void putNumber(long long int n) {
	char digit;
	if (n >= 10)
		putNumber(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}*/

static bool areOnlyNumber(char *str) {
	while (*str) {
		if (*str < '0' || *str > '9')
			return (false);
		++str;
	}
	return (true);
}

/*static long long int numberConversor(char *str, bool *err) {
	long long int result = 0;
	long long int signal = 1;
	int count = 0;

	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' || *str == '\r'
			|| *str == '\b' || *str == '\a')
		++str;
	while (*str == '+' || *str == '-') {
		if (*str == '-') {
			*err = true;
			return (0);
		}
		++str;
	}
	while (*str >= '0' && *str <= '9') {
		++count;
		if (count == 21) {
			*err = true;
			return (0);
		}
		result *= 10;
		result += *str - '0';
		++str;
	}
	return (result * signal);
}*/

static void isLuckyNumber(char *str) {
	bool alert = false;
	long long hasFour = 0;
	long long hasSeven = 0;

	while (*str) {
		if (*str == '4') {
			++hasFour;
		} else if (*str == '7') {
			++hasSeven;
		}
		++str;
	}
	long long result = hasFour + hasSeven;

	if (alert || (result != 4 && result != 7))
		write(1, "NO\n", 3);
	else if (result == 4 || result == 7)
		write(1, "YES\n", 4);
	return ;
}

int main(void) {
	char *input = (char *)calloc(100, sizeof(char *));

	if (!input) {
		//write(2, "Error\n", 6);
		return (0);
	}
	scanf("%s", input);
	if (input[0] == '\0' || !areOnlyNumber(input)) {
		//write(2, "Error\n", 6);
		free(input);
		return (0);
	}
	isLuckyNumber(input);
	free(input);
	return (0);
}
