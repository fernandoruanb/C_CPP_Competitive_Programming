#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_LEN 102

static int numberConversor(char *input, bool *err) {
	long result = 0;
	int signal = 1;

	while (*input == ' ' || *input == '\t' || *input == '\n' || *input == '\v'
		|| *input == '\f' || *input == '\a' || *input == '\b' || *input == '\r')
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

static bool isAllNumbers(const char *input) {
	while (*input) {
		if ((*input < '0' || *input > '9') && *input != '\n' && *input != '+')
			return (false);
		++input;
	}
	return (true);
}

int main(void) {
	char input[MAX_LEN];

	fgets(input, MAX_LEN, stdin);
	if (!input || !isAllNumbers(input)) {
		//write(2, "Invalid Input\n", 14);
		return (0);
	}
	bool err = false;
	int weight = numberConversor(input, &err);
	if (err) {
		//write(2, "Input Error\n", 12);
		return (0);
	}
	int divided = weight >> 1;
	int result = divided / 2;
	if (result % 2 == 0)
		write(1, "YES\n", 4);
	else
		write(1, "NO\n", 3);
	return (0);
}
