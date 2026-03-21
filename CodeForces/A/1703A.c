#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_LEN 1002

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/1703/A
        I am happy to code :)
*/

static size_t strLen(char *str) {
	size_t length = 0;
	while (*(str + length) != '\0' && *(str + length) != '\n')
		++length;
	return (length);
}

static int strCheck(char *str) {
	size_t length = strLen(str);

	if (length < 3)
		return (false);
	if ((str[0] == 'y' || str[0] == 'Y') && (str[1] == 'e' || str[1] == 'E') && (str[2] == 's'
		|| str[2] == 'S'))
		return (true);
	return (false);
}

int main(void) {
	int input;

	scanf("%d", &input);

	if (!input)
		return (0);

	char result[MAX_LEN];
	char str[MAX_LEN];
	int index = 0;
	int check;

	while (input--) {
		check = sizeof(str);
		while (check--)
			str[check] = '\0';
		scanf("%s", str);
		if (strCheck(str))
			result[index++] = 'Y';
		else
			result[index++] = 'N';
	}
	result[index] = '\0';
	index = 0;
	while (result[index]) {
		if (result[index] == 'Y')
			write(1, "YES\n", 4);
		else if (result[index] == 'N')
			write(1, "NO\n", 3);
		++index;
	}
	return (0);
}
