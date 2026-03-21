#include <stdio.h>
#include <strings.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_LEN 102

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/791/A
        I am happy to code :)
*/

static void putNumber(int n) {
	char digit;

	if (n >= 10)
		putNumber(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

static int numberConversor(char *str, bool *err) {
	long result = 0;
	int signal = 1;

	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\a'
		|| *str == '\r' || *str == '\v' || *str == '\f')
		++str;
	while (*str == '+' || *str == '-') {
		if (*str == '-')
			signal *= -1;
		++str;
	}
	while (*str >= '0' && *str <= '9') {
		result *= 10;
		result += *str - '0';
		if (result > INT_MAX || (result * signal) < INT_MIN) {
			*err = true;
			return (0);
		}
		++str;
	}
	return ((int)result * signal);
}

static int calculateAnswer(char *input, bool *error) {

	char extracted[MAX_LEN];
	int a = -1;
	int b = -1;
	int	index = 0;
	int	count = 0;
	int	result = 0;
	bool err = false;

	while (*input) {
		if (*input >= '0' && *input <= '9')
			extracted[index++] = *input;
		else if (*input == ' ' || *input == '\n') {
			extracted[index] = '\0';
			if (count == 0) {
				a = numberConversor(extracted, &err);
				while (index) 
					extracted[index--] = '\0';
			} else if (count == 1) 
				b = numberConversor(extracted, &err);
			else if (count > 1) {
				*error = true;
				return (0);
			}
			++count;
		}
		if (err)
			return (0);
		++input;
	}
	while (a <= b) {
		a *= 3;
		b *= 2;
		++result;
	}
	if (a == -1 || b == -1) {
		*error = true;
		return (0);
	}
	return (result);
}

static bool checkNumbers(char *input) {

	while (*input) {
		if ((*input < '0' || *input > '9') && *input != ' ' && *input != '\n')
			return (false);
		++input;
	}
	return (true);
}

int main(void) {
	char input[MAX_LEN];
	bool error = false;

	fgets(input, MAX_LEN, stdin);
	int result = calculateAnswer(input, &error);
	if (error)
		return (0);
	putNumber(result);
	write(1, "\n", 1);
	return (0);
}
