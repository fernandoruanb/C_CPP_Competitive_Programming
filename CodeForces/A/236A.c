#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_LEN 102

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/236/A
        I am happy to code :)
*/

static bool hasLetter(char c, char *letters, int index) {
	letters[index] = '\0';
	while (*letters) {
		if (*letters == c)
			return (true);
		++letters;
	}
	return (false);
}

static void discoverGender(char *input) {
	char letters[MAX_LEN];
	int	index = 0;
	int	count = 0;

	while (*input) {
		if (*input >= 'a' && *input <= 'z') {
			if (!hasLetter(*input, letters, index)) {
				letters[index++] = *input;
				++count;
			}
		} else if (*input >= 'A' && *input <= 'Z') {
			if (!hasLetter(*input, letters, index)) {
				letters[index++] = *input;
				++count;
			}
		}
		++input;
	}
	if (count % 2 == 0)
		write(1, "CHAT WITH HER!\n", 15);
	else
		write(1, "IGNORE HIM!\n", 12);
	return ;
}

int main(void) {
	char input[MAX_LEN];
	
	fgets(input, MAX_LEN, stdin);
	if (input[0] == '\n' || input[0] == '\0')
		return (0);
	discoverGender(input);
	return (0);
}
