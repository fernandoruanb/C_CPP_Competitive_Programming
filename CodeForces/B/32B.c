#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_LEN 2002

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/32/B
        I am happy to code :)
*/

static void getTheTernaryNumber(char *input) {
	char buffer[MAX_LEN];
	char checker[MAX_LEN];
	int counter = 0;
	int index = 0;

	while (*(input + index) != '\n' && (*input + index) != '\0') {
		if (index == 0 && *input == '.' || (*(input + index + 1) == '\n' || *(input + index + 1) == '\0')
			&& *(input + index) == '.') {
			buffer[counter++] = '0';
			++index;
			continue ;
		}
		checker[0] = *(input + index);
		checker[1] = *(input + index + 1);
		if (checker[0] == '-' && checker[1] == '-') {
			buffer[counter++] = '2';
			index += 2;
			continue ;
		} else if (checker[0] == '.' && checker[1] == '-') {
			buffer[counter++] = '0';
			++index;
			continue ;
		} else if (checker[0] == '-' && checker[1] == '.') {
			buffer[counter++] = '1';
			index += 2;
			continue ;
		} else if (checker[0] == '.' && checker[1] == '.') {
			buffer[counter++] = '0';
			buffer[counter++] = '0';
			index += 2;
		} else
			++index;
	}
	index = 0;
	while (index < counter)
		write(1, &buffer[index++], 1);
	write(1, "\n", 1);
}

int main(void) {
	char input[MAX_LEN];

	fgets(input, MAX_LEN, stdin);

	if (input[0] == '\0' || input[0] == '\n')
		return (0);
	getTheTernaryNumber(input);
	return (0);
}
