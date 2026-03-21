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
}*/

static bool check_numbers(char *str) {
	bool hasNumber = false;
	while (*str) {
		if (*str >= '0' && *str <= '9' && !hasNumber)
			hasNumber = true;
		else if ((*str < '0' || *str > '9') && (*str != '\n'
			&& *str != ' ' && *str != '-' && *str != '+' && *str != '\0'))
			return (false);
		++str;
	}
	if (!hasNumber && *str == '\0') 
		return (false);
	return (true);
}

static bool	global_checker(int n, int counter) {
	static int x = 0;
	static int y = 0;
	static int z = 0;

	if (counter == 1)
		x += n;
	else if (counter == 2)
		y += n;
	else if (counter == 3)
		z += n;
	else
		if (x == 0 && y == 0 && z == 0)
			return (true);
	return (false);
}

static void	extractor_of_numbers(char *str, bool *err) {
	char	buffer[102];
	int	extracted = 0;
	int	index = 0;
	int	check = 0;
	int	count = 0;

	if (!check_numbers(str)) {
		*err = true;
		return ;
	}

	while (*str) {
		if (index == 102) {
			*err = true;
			return ;
		}
		else if (*str == ' ' || *str == '\0' || *str == '\n') {
			++count;
			buffer[index + 1] = '\0';
			extracted += number_conversor(buffer, err);
			if (*err) 
				return ;
			global_checker(extracted, count);
			check = sizeof(buffer);
			while (check--)
				buffer[check] = '\0';
			extracted = 0;
			index = 0;
		}
			
		else if ((*str >= '0' && *str <= '9') || (*str == '-' || *str == '+')) {
			buffer[index] = *str;
			++index;
		}
		++str;
	}
	if (count != 3) {
		*err = true;
		return ;
	}
	return ;
}

int main(void) {
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
		if (tmp[0] == '\n' || tmp[0] == '\n') {
			//write(2, "Invalid input\n", 13); 
			return (0);
		}
		extractor_of_numbers(tmp, &err);
		if (err) {
			//write(2, "Error\n", 6);
			return (0);
		}
	}

	if (global_checker(0, 4))
		write(1, "YES\n", 4);
	else 
		write(1, "NO\n", 3);
	return (0);
}
