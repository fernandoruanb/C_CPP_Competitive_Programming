#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_LEN 102

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/271/A
        I am happy to code :)
*/

static int numberConversor(char *n, bool *err) {
	long result = 0;
	int signal = 1;

	while (*n == ' ' || *n == '\t' || *n == '\v' || *n == '\f' || *n == '\a'
		|| *n == '\b' || *n == '\r')
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
	return ((int)result * signal);
}

static ssize_t calculateNumberLength(int n) {
	ssize_t length = 0;

	if (n <= 0)
		length = 1;
	while (n) {
		n /= 10; // decimal base
		++length;
	}
	return (length);
}

static size_t strLen(char *str) {
	size_t length = 0;
	while (*(str + length) != '\n' && *(str + length) != '\0')
		++length;
	return (length);
}

static char *tunnelNumberToStr(char *str) {
	size_t length = strLen(str);
	char *buffer = (char *)calloc(10, sizeof(char *));
	size_t index = 0;
	while (*(str + index) != '\n' && *(str + index) != '\0') {
		buffer[index] = *(str + index);
		++index;
	}
	buffer[index] = '\0';
	return (buffer);
}

static char *strConversor(int n) {
	char	*buffer;
	ssize_t	length;
	ssize_t	number;

	if (n == -2147483648)
		return (tunnelNumberToStr("-2147483648"));
	if (n < 0)
		number = -n;
	else
		number = n;
	length = calculateNumberLength(n);
	buffer = (char *)calloc(1, length + 1);
	if (!buffer)
		return (NULL);
	buffer[length] = '\0';
	while (length--) {
		buffer[length] = (number % 10) + '0';
		number /= 10;
	}
	return (buffer);
}

static void printStr(char *str) {
	char digit;

	while (*str) {
		digit = *str;
		write(1, &digit, 1);
		++str;
	}
	write(1, "\n", 1);
	return ;
}

static bool isDistinct(char *target) {
	char c = *target;
	int counter = strLen(target);
	int count = 0;
	int index = 0;
	int protected = 0;
	while (*(target + protected)) {
		c = *(target + protected);
		count = 0;
		index = 0;
		while (*(target + index)) {
			if (*(target + index) == c)
				++count;
			++index;
		}
		if (count > 1)
			return (false);
		++protected;
	}
	return (true);
}

static void findNextDistinctNumber(int n) {
	int next = n + 1;
	char *target;

	while (1) {
		target = strConversor(next);
		if (!target)
			return ;
		else if (isDistinct(target)) {
			printStr(target);
			free(target);
			return ;
		}
		if (next == 3000)
			break ;
		++next;
		free(target);
	}
	return ;
}

int main(void) {
	char input[MAX_LEN];
	bool err = false;

	fgets(input, MAX_LEN, stdin);
	if (input[0] == '\n' || input[0] == '\0') {
		write(2, "Error\n", 6);
		return (0);
	}
	int number = numberConversor(input, &err);
	if (err || !number) {
		write(2, "Error\n", 6);
		return (0);
	}
	findNextDistinctNumber(number);
	return (0);
}
