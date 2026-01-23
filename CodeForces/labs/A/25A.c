#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <unistd.h>

#define MAX_LEN 1000002

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/25/A
        I am happy to code :)
*/

static int numberConversor(char *n, bool *err) {
	long result = 0;
	long signal = 1;

	while (*n == '\0' || *n == '\t' || *n == '\r' || *n == '\v'
		|| *n == ' ' || *n == '\n' || *n == '\f' || *n == '\a')
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

static void putNumber(int n) {
	char digit;

	if (n >= 10)
		putNumber(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

static bool checkEvenOdd(int target, int maximum) {
	static int index = 1;
	static int firstOdd = 0;
	static int firstEven = 0;
	static int even = 0;
	static int odd = 0;

	if (target % 2 == 0) {
		if (firstEven == 0)
			firstEven = index;
		++even;
	}
	else if (target % 2 == 1) {
		if (firstOdd == 0)
			firstOdd = index;
		++odd;
	}
	if (index == maximum) {
		if (even > odd)
			putNumber(firstOdd);
		else
			putNumber(firstEven);
		return (true);
	}
	++index;
	return (false);
}

static void findIntruderIndex(char *input, bool *err, int maximum) {
	int index = 0;
	int newTarget = 0;
	char number[MAX_LEN];

	while (*input) {
		if (*input == ' ' || *(input + 1) == '\0') {
			newTarget = numberConversor(number, err);
			if (*err) {
				write(2, "Error\n", 6);
				return ;
			}
			if (checkEvenOdd(newTarget, maximum))
				break ;
			while (index)
				number[index--] = '\0';
		}
		else if (*input >= '0' && *input <= '9')
			number[index++] = *input;
		else {
			*err = true;
			write (2, "Error\n", 6);
			return ;
		}
		++input;
	}
	return ;
}

static bool isValidInput(char *input) {
	int index = 0;
	while (*(input + index)) {
		if (index == 0 && (*(input + index) < '0' || *(input + index) > '9'))
			return (false);
		else if (index > 0 && (*(input + index) < '0' || *(input + index) > '9') && *(input + index) != ' ' && *(input + index) != '\n')
			return (false);
		++index;
	}
	return (true);
}

static bool hasEnoughNumbers(char *sequence, int all) {
	bool hasNumber = false;
	int counter = 0;

	while (*sequence) {
		if (*sequence == ' ' || *sequence == '\n' || *sequence == '\0') {
			if (hasNumber) {
				if (counter > all)
					return (false);
				++counter;
			}
			hasNumber = false;
		}
		else if (*sequence >= '0' && *sequence <= '9')
			hasNumber = true;
		++sequence;
	}
	if (counter != all)
		return (false);
	return (true);
}

int main(void) {
	char input[MAX_LEN];
	char sequence[MAX_LEN];
	bool err = false;

	fgets(input, MAX_LEN, stdin);
	if (input[0] == '\n' || input[0] == '\0') {
		write(2, "Error\n", 6);
		return (0);
	}
	if (!isValidInput(input))
		return (0);
	fgets(sequence, MAX_LEN, stdin);
	int index = numberConversor(input, &err);
	if (!hasEnoughNumbers(sequence, index))
		return (0);
	findIntruderIndex(sequence, &err, index);
	if (!err)
		write(1, "\n", 1);
	return (0);
}
