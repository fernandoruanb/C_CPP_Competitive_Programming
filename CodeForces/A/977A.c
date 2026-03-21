#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/977/A
        I am happy to code :)
*/

static int letsSubtract(int number, int times) {
	int lastDigit;
	int result = number;

	while (times--) {
		lastDigit = result % 10;
		if (lastDigit == 0)
			result /= 10;
		else
			result -= 1;
	}
	return (result);
}

int main(void) {
	int *input = (int *)calloc(2, sizeof(int));

	if (!input)
		return (0);

	for (int i = 0; i < 2; ++i)
		scanf("%d", input + i);

	int result = letsSubtract(input[0], input[1]);
	printf("%d\n", result);
	free(input);
	return (0);
}
