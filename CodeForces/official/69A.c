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

#define MAX_LEN 102

static int number_conversor(const char *str, bool *err) {
	long result = 0;
	int signal = 1;

	while (*str == '\n' || *str == '\f' || *str == '\a' || *str == '\b'
		|| *str == ' ' || *str == '\t' || *str == '\v' || *str == '\r')
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

/*static void advance_pointer(int positions, char ***argv) {
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
}*/

static int	extractor_of_numbers(char *str, bool *err) {
	char	buffer[102];
	int	extracted = 0;
	int	official = 0;
	int	index = 0;
	int	check = 0;

	while (*str) {
		if (index == 102) {
			*err = true;
			return (0);
		}
		else if (*str == ' ' || *str == '\0' || *str == '\n') {
			buffer[index + 1] = '\0';
			extracted += number_conversor(buffer, err);
			if (*err) 
				return (0);
			check = sizeof(buffer);
			while (check--)
				buffer[check] = '\0';
			official += extracted;
			extracted = 0;
			index = 0;
		}
			
		else if ((*str >= '0' && *str <= '9') || (*str == '-' || *str == '+')) {
			buffer[index] = *str;
			++index;
		}
		++str;
	}
	return (official);
}

int main(void) {
	int result = 0;
	char	tmp[MAX_LEN];

	// Numbers are dangerous in C language, so I made a function to limitate and avoid overflow and underflow
	bool err = false;

	// I check here if the use put a coordinate and you do not have enough values
	char coordinates[MAX_LEN];
	fgets(coordinates, MAX_LEN, stdin);

	int index = number_conversor(coordinates, &err);
	if (err || index < 1 || index > 100) {
		//write(2, "Invalid Index\n", 14);
		return (0);
	}

	int	check;

	while (index--) {
		check = sizeof(tmp);
		while (check--)
			tmp[check] = '\0';
		fgets(tmp, MAX_LEN, stdin);
		if (tmp[0] == '\0') 
			return (0);
		result += extractor_of_numbers(tmp, &err);
		if (err) {
			//write(2, "Error\n", 6);
			return (0);
		}
	}

	if (result == 0)
		write(1, "YES\n", 4);
	else 
		write(2, "NO\n", 3);
	return (0);
}
