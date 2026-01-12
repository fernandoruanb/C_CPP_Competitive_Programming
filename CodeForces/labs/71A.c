#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_LEN 102

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/71/A
        I am happy to code :)
*/

static int number_conversor(char *str, bool *err) {
	long result = 0;
	int signal = 1;

	while (*str == ' ' || *str == '\n' || *str == '\f' || *str == '\v'
		|| *str == '\t' || *str == '\r' || *str == '\a')
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

static void putNumber(int n) {
	char	digit;

	if (n >= 10)
		putNumber(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

static int strLen(char *target) {
	int	index = 0;
	while (*(target + index))
		++index;
	return (index);
}

static void putStr(char *str) {
	while (*str) {
		write(1, &(*str), 1);
		++str;
	}
}

static void putWithValidation(char *str) {
	int length = strLen(str);
	if ((length - 1) > 10) {
		write(1, &str[0], 1);
		putNumber(length - 3);
		write(1, &str[length - 2], 1);
		write(1, "\n", 1);
	} else {
		putStr(str);
	}
}

static bool isNumber(char *str) {
	while (*str) {
		if ((*str < '0' || *str > '9') && *str != '\n')
			return (false);
		++str;
	}
	return (true);
}

int main(void) {
	char str[MAX_LEN];
	bool err = false;
	char bank[MAX_LEN][MAX_LEN];

	fgets(str, MAX_LEN, stdin);
	if (str[0] == '\n' || str[0] == '\0') {
		//write(2, "Error\n", 6);
		return (0);
	}
	if (!isNumber(str))
		return (0);
	int index = number_conversor(str, &err);
	if (err) {
		//write(2, "Error\n", 6);
		return (0);
	}
	char	tmp[MAX_LEN];
	int checker = sizeof(tmp);
	int count = 0;
	while (index--) 
		fgets(bank[count++], MAX_LEN, stdin);

	int	i = 0;

	while (i < count) {
		putWithValidation(bank[i]);
		++i;
	}
	return (0);
}
