#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_LEN 1102

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/443/A
        I am happy to code :)
*/

static void checkDifferentLetters(char *input) {
	char letters[MAX_LEN];
	int counter = 0;
	bool flag = false;
	int index = 0;

	while (*input) {
		if ((*input >= 'a' && *input <= 'z') || (*input >= 'A' && *input <= 'Z')) {
			if (counter == 0)
				letters[counter++] = *input;
			else {
				index = 0;
				flag = false;
				while (index < counter) {
					if (letters[index] == *input) {
						flag = true;
						break ;
					}
					++index;
				}
				if (!flag)
					letters[counter++] = *input;
			}
		}
		++input;
	}
	printf("%d\n", counter);
}

int main(void) {
	char input[MAX_LEN];

	fgets(input, MAX_LEN, stdin);
	if (input[0] == '\0' || input[0] == '\n')
		return (0);
	checkDifferentLetters(input);
	return (0);
}
