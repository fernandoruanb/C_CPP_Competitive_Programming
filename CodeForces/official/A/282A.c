#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_LEN 152

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/282/A
        I am happy to code :)
*/

static int strLen(char *str) {
	int length = 0;
	while (*(str + length)) {
		if(length > 150)
			return (151);
		++length;
	}
	return (length);
}

static void putNumber(int n) {

	if (n == -2147483648) {
		write(1, "-2147483648\n", 11);
		return ;
	}

	char digit;

	if (n < 0) {
		write(1, "-", 1);
		n = -n;
	}

	if (n >= 10)
		putNumber(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

static int number_conversor(char *input, bool *err) {
	long result = 0;
	int signal = 1;

	while (*input == ' ' || *input == '\t' || *input == '\n' || *input == '\v'
		|| *input == '\f' || *input == '\r' || *input == '\a')
		++input;
	while (*input == '+' || *input == '-') {
		if (*input == '-')
			signal *= -1;
		++input;
	}
	while (*input >= '0' && *input <= '9') {
		result *= 10;
		result += *input - '0';
		if (result > INT_MAX || (result * signal) < INT_MIN) {
			*err = true;
			return (0);
		}
		++input;
	}
	return ((int)result * signal);
}

static void makeValue(char *input, bool flag, bool *err) {
	static int x = 0;

	int length = 0;

	if (!flag) {
		length = strLen(input);

		if (length != 4) {
			*err = true;
			return ;
		}

		if (*input == '-' && *(input + 1) == '-' && *(input + 2) == 'X')
			--x;
		else if (*input == '+' && *(input + 1) == '+' && *(input + 2) == 'X')
			++x;
		else if (*input == 'X' && *(input + 1) == '+' && *(input + 2) == '+')
			x++;
		else if (*input == 'X' && *(input + 1) == '-' && *(input + 2) == '-')
			x--;
		else {
			*err = true;
			return ;
		}
	} else if (flag) {
		putNumber(x);
	}
}

static bool checkInput(char *input) {
	while (*input) {
		if ((*input < '0' || *input > '9') && *input != '\n')
			return (false);
		++input;
	}
	return (true);
}

int main(void) {
	char input[MAX_LEN];

	fgets(input, MAX_LEN, stdin);

	bool err = false;
	if (!checkInput(input))
		return (0);
	int index = number_conversor(input, &err);

	if (err || index < 1 || index > 150) {
		//write(2, "Error\n", 6);
		return (0);
	}
	char bank[MAX_LEN][MAX_LEN];
	int  count = 0;

	while (index--) 
		fgets(bank[count++], MAX_LEN, stdin);
	int i = 0;
	while (i < count) {
		makeValue(bank[i++], false, &err);
		if (err)
			return (0);
	}
	makeValue(NULL, true, &err);
	if (err)
		return (0);
	write(1, "\n", 1);
	return (0);
}
