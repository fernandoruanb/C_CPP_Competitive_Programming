#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_LEN 10002

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/131/A
        I am happy to code :)
*/

static ssize_t strLen(char *str) {
	ssize_t length = 0;

	while (*(str + length) != '\n' && *(str + length) != '\0')
		++length;
	return (length);
}

static bool isCapsLock(char *input, ssize_t length, bool *flag) {
	ssize_t index = 0;

	while (index < length) {
		if (input[index] >= 'A' && input[index] <= 'Z')
			++index;
		else
			break ;
	}
	if (index == length) {
		char digit;

		index = 0;
		while (index < length) {
			digit = input[index] + 32;
			write(1, &digit, 1);
			++index;
		}
		*flag = true;
		return(true);
	}
	index = 0;
	while (index < length - 1) {
		if (input[0] >= 'a' && input[index] <= 'z' && input[index + 1] >= 'A'
			&& input[index + 1] <= 'Z')
			++index;
		else
			break ;
	}
	if (index == length - 1)
		return (true);
	return (false);
}

static void capsLock(char *input) {
	ssize_t length = strLen(input);
	ssize_t index = 0;
	char digit;
	bool flag = false;

	if (isCapsLock(input, length, &flag)) {
		if (flag)
			return ;
		while (index < length) {
			if (index == 0 && input[index] >= 'a' && input[index] <= 'z') {
				digit = input[index] - 32;
				write(1, &digit, 1);
			} else if (index > 0 && input[index] >= 'A' && input[index] <= 'Z'){
				digit = input[index] + 32;
				write(1, &digit, 1);
			}
			else {
				digit = input[index];
				write(1, &digit, 1);
			}
			++index;
		}
	} else {
		while (*input != '\n' && *input != '\0') {
			digit = *input;
			write(1, &digit, 1);
			++input;
		}
	}
	return ;
}

int main(void) {
	char input[MAX_LEN];

	fgets(input, MAX_LEN, stdin);
	if (input[0] == '\0' || input[0] == '\n')
		return (0);
	capsLock(input);
	write(1, "\n", 1);
	return (0);
}
