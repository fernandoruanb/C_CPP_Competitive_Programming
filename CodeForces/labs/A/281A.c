#include <stdio.h>
#include <unistd.h>

#define MAX_LEN 10002

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/281/A
        I am happy to code :)
*/

static void strCapitalize(char *str) {
	char digit;

	if (*str >= 'A' && *str <= 'Z') {
		write(1, str, 1);
		++str;
	} else {
		digit = *str - 32;
		write(1, &digit, 1);
		++str;
	}
	while (*str) {
		write(1, str, 1);
		++str;
	}
}

int	main(void) {
	char input[MAX_LEN];

	fgets(input, MAX_LEN, stdin);
	if (input[0] == '\0' || input[0] == '\n')
		return (0);
	strCapitalize(input);
	return (0);
}
