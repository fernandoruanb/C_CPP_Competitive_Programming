#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/1030/A
        I am happy to code :)
*/

int main(void) {
	int index;

	scanf("%d", &index);

	if (!index || index < 1)
		return (0);

	int *input = (int *)calloc(index, sizeof(int));

	if (!input)
		return (0);

	for (int i = 0; i < index; ++i)
		scanf("%d", input + i);

	bool hard = false;

	for (int i = 0; i < index; ++i) {
		if (input[i] == 1) {
			hard = true;
			break ;
		}
	}
	if (!hard)
		printf("EASY\n");
	else
		printf("HARD\n");
	free(input);
	return (0);
}
