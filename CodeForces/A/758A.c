#include <stdio.h>
#include <stdlib.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/758/A
        I am happy to code :)
*/

static int findMaxValue(int *citizens, int input) {
	int max = 0;
	for (int i = 0; i < input; ++i) {
		if (citizens[i] > max)
			max = citizens[i];
	}
	return (max);
}

int main(void) {
	int input;

	scanf("%d", &input);

	if (input < 0 || input > 100)
		return (0);

	int *citizens = (int *)calloc(input, sizeof(int));
	if (!citizens)
		return (0);
	for (int i = 0; i < input; ++i) {
		scanf("%d", citizens + i);
	}
	int maxValue = findMaxValue(citizens, input);
	int result = 0;
	for (int i = 0; i < input; ++i) {
		if (citizens[i] != maxValue)
			result += maxValue - citizens[i];
	}
	printf("%d\n", result);
	free(citizens);
	return (0);
}
