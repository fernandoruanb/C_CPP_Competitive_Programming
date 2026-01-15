#include <stdio.h>
#include <stdbool.h>
#include <limits.h>
#include <unistd.h>

#define MAX_LEN 102

static int numberConversor(char *n, bool *err) {
	long result = 0;
	long signal = 1;

	while (*n == '\0' || *n == '\t' || *n == '\r' || *n == '\v'
		|| *n == ' ' || *n == '\f' || *n == '\a')
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

static bool checkIntruder(int target) {
	static int pattern = 0;
	static int lastChecked = 0;
	static int index = 0;

	printf("O target: %d\n", target);
	if (index == 1)
		pattern = target - lastChecked;
	else if (index > 1 && pattern != (target - lastChecked)) {
		putNumber(index + 1);
		return (true);
	}
	lastChecked = target;
	++index;
	return (false);
}

static void findIntruderIndex(char *input, bool *err) {
	int index = 0;
	int newTarget = 0;
	char number[MAX_LEN];

	while (*input != '\n' && *input != '\0') {
		if (*input == ' ' || *(input + 1) == '\0') {
			newTarget = numberConversor(number, err);
			if (*err) {
				write(2, "Error\n", 6);
				return ;
			}
			if (checkIntruder(newTarget))
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

int main(void) {
	char input[MAX_LEN];
	char sequence[MAX_LEN];
	bool err = false;

	fgets(input, MAX_LEN, stdin);
	if (input[0] == '\n' || input[0] == '\0') {
		write(2, "Error\n", 6);
		return (0);
	}
	fgets(sequence, MAX_LEN, stdin);
	int index = numberConversor(input, &err);
	findIntruderIndex(sequence, &err);
	if (!err)
		write(1, "\n", 1);
	return (0);
}
