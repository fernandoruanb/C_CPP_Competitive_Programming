#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <unistd.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/69/A
        I am happy to code :)
*/

// my number_conversor is based in the atoi function, but I improved it. You can check it using man atoi in the shell

static int number_conversor(const char *str, bool *err) {
	long result = 0;
	int signal = 1;

	while (*str == '\n' || *str == '\f' || *str == '\a' || *str == '\b'
		|| *str == '\v' || *str == '\r')
			++str;
	while (*str == '+' || *str == '-') {
		if (*str == '-')
			signal *= -1; // creating the special effect -(-10) = 10
		++str;
	}
	while (*str >= '0' && *str <= '9') {
		result *= 10;
		result += *str - '0';
		if (result > INT_MAX || result < INT_MIN) {
			*err = true;
			return (0);
		}
		++str;
	}
	if ((result * signal) < -100 || result > 100) {
		*err = true;
		return (0);
	}
	return ((int)result * signal);
}

static void advance_pointer(int positions, char ***argv) {
	if (!positions)
		return ;
	while (positions) {
		++(*argv);
		--positions;
	}
	return ;
}

static bool check_numbers(char *argv) {
	while (*argv) {
		int hasNumber = false;
		if (*argv >= '0' && *argv <= '9' && !hasNumber)
			hasNumber = true;
		if (!hasNumber && *(argv + 1) == '\0')
			return (false);
		if ((*argv < '0' || *argv > '9') && *argv != '-' && *argv != '+')
			return (false);
		++argv;
	}
	return (true);
}

int main(int argc, char **argv) {
	if (argc < 3) {
		write(2, "Input Error\n", 12);
		return (-1);
	}
	int result = 0;

	// Numbers are dangerous in C language, so I made a function to limitate and avoid overflow and underflow
	bool err = false;

	// I check here if the use put a coordinate and you do not have enough values
	int index = number_conversor(*(argv + 1), &err);
	if (index < 1 || index > 100) {
		write(2, "Invalid Index\n", 14);
		return (-5);
	}
	if (((argc - 2) % index) != 0) {
		write(2, "Missed value\n", 13);
		return (-2);
	}
	// I made a function only to advance the main pointer of argv to catch the values directly
	advance_pointer(2, &argv);
	char **test = argv;

	// Check if everything is numbers, the only exception is + and - because I handle with them

	while (*test) {
		if (!check_numbers(*test)) {
			write(2, "Only numbers\n", 13);
			return (-3);
		}
		++test;
	}
	while (*argv) {
		err = false;
		result += number_conversor(*argv, &err);
		if (err) {
			write(2, "Value Error\n", 12);
			return (-4);
		}
		++argv;
	}
	if (result == 0 && !err)
		write(1, "YES\n", 4);
	else
		write(2, "NO\n", 3);
	return (0);
}
