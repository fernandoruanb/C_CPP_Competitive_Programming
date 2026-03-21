#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_LEN 12

/*
	Author: Fernando Ruan
	Profile: https://codeforces.com/profile/fruan-ba
	Country: Brazil
	ChallengeLink: https://codeforces.com/problemset/problem/479/A
	I am happy to code :)
*/

static void putNumber(int n) {
	char digit;

	if (n >= 10)
		putNumber(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

static int numberConversor(char *n, bool *err) {
	long result = 0;
	int signal = 1;

	while (*n == ' ' || *n == '\t' || *n == '\n' || *n == '\v' || *n == '\r'
		|| *n == '\f' || *n == '\a' || *n == '\b')
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

static void checkMaxValuePossible(int a, int b, int c) {
	int first = a + b * c;
	int second = a * (b + c);
	int third = a * b * c;
	int fourth =  (a + b) * c;
	int fifth = a + b + c;
	int max = 0;
	
	if (first > second)
		max = first;
	else
		max = second;
	if (third > max)
		max = third;
	if (fourth > max)
		max = fourth;
	if (fifth > max)
		max = fifth;
	putNumber(max);
	write(1, "\n", 1);
}

int main(void) {
	char get[MAX_LEN];
	int a = 0;
	int b = 0;
	int c = 0;
	bool err = false;
	int	input = 0;

	while (input < 3) {
		fgets(get, MAX_LEN, stdin);
		if (input == 0)
			a = numberConversor(get, &err);
		else if (input == 1)
			b = numberConversor(get, &err);
		else if (input == 2)
			c = numberConversor(get, &err);
		++input;
		if (err)
			return (0);
	}
	checkMaxValuePossible(a, b, c);
	return (0);
}
