#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

#define STONES_LEN 52

/*
	Author: Fernando Ruan
	Profile: https://codeforces.com/profile/fruan-ba
	Country: Brazil
	ChallengeLink: https://codeforces.com/problemset/problem/266/A
	I am happy to code :)
*/

static int number_conversor(char *str, bool *err) {
	long result = 0;
	int signal = 1;
	
	while (*str == '\n' || *str == '\f' || *str == '\v' || *str == '\r'
			|| *str == '\b' || *str == '\a' || *str == ' ' || *str == '\t')
		++str;
	while (*str == '+' || *str == '-') {
		if (signal == '-')
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

static bool areValid_stones(char *stones) {
	char *valid = "RGB";
	int index = 0;

	while (*stones) {
		index = 0;
		while (valid[index]) {
			if (*stones == valid[index] || *stones == valid[index] + 32)
				break ;
			++index;
		}
		if (!valid[index])
			return (false);
		++stones;
	}
	return (true);
}

static bool checkLength(int stones, char *stonesStr) {
	long length = 0;
	while (*(stonesStr)++) 
		++length;
	if (length != stones)
		return (false);
	return (true);
}

static void putNumber(int number) {
	char	digit;

	if (number == INT_MIN) {
		write(1, "-2147483648", 11);
		return ;
	}

	if (number < 0) {
		write(1, "-", 1);
		number = -number;
	}

	if (number >= 10)
		putNumber(number / 10); // recursion to print the number

	digit = '0' + (number % 10);
	write(1, &digit, 1); // print each digit
}

static int check_remove_stones(char *stones) {
	int count = 0;
	while (*stones) {
		if ((*stones == 'R' || *stones == 'r') && (*(stones + 1) == 'R' || *(stones + 1) == 'r'))
			++count;
		else if ((*stones == 'G' || *stones == 'g') && (*(stones + 1) == 'G' || *(stones + 1) == 'g'))
			++count;
		else if ((*stones == 'B' || *stones == 'b') && (*(stones + 1) == 'B') || *(stones + 1) == 'b')
			++count;
		++stones;	
	}
	return (count);
}

static int my_strlen(const char *str) {
	int	length = 0;
	while (*(str + length)) {
		++length;
	}
	return (length);
}

static char *fix_string(char *str) {
	int length = my_strlen(str);
	str[length - 1] = '\0';
	return (str);
}

int main(void) {

	char index[STONES_LEN];
	char stonesStr[STONES_LEN];
	char *final = NULL;

	fgets(index, STONES_LEN, stdin);
	fgets(stonesStr, STONES_LEN, stdin);

	final = fix_string(stonesStr);

	if (!index || !stonesStr) {
		//write(2, "Error\n", 6);
		return (0);
	}

	bool err = false;
	int stones = number_conversor(index, &err);

	if (err || stones < 1 || stones > 50) {
		//write(2, "Invalid Value\n", 14);
		return (0);
	}

	if (!checkLength(stones, final)) {
		//write(2, "Stones Value Error\n", 19);
		return (0);
	}

	if (!areValid_stones(final)) {
		//write(2, "Stones Error\n", 13);
		return (0);
	}

	int removeStones = check_remove_stones(stonesStr);
	putNumber(removeStones);
	write(1, "\n", 1);
	return (0);
}
