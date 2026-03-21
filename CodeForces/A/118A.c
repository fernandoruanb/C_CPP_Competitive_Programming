#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_LEN 10002

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/118/A
        I am happy to code :)
*/

static void encodingString(char *input) {
	const char *vowels = "aeiouyAEIOUY";
	bool flag = false;
	char digit = '\0';
	int index = 0;

	while (*input != '\n' && *input != '\0') {
		index = 0;
		flag = false;
		while (vowels[index]) {
			if (*input == vowels[index]) {
				++input;
				flag = true;
				break ;
			}
			++index;
		}
		if (flag)
			continue ;
		write(1, ".", 1);
		if (*input >= 'A' && *input <= 'Z') {
			digit = *input + 32;
			write(1, &digit, 1);
		} else {
			digit = *input;
			write(1, &digit, 1);
		}
		++input;
	}
}

int main(void) {
	char input[MAX_LEN];

	fgets(input, MAX_LEN, stdin);
	if (input[0] == '\n' || input[0] == '\0')
		return (0);
	encodingString(input);	
	write(1, "\n", 1);
	return (0);
}
