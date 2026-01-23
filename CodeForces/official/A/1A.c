#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/1/A
        I am happy to code :)
*/

/*
	How do we need to think that problem?
	First, we need to calculate the dimensions
	n / a and m / a
	if we detect rest, we add 1
	so, we multiply both
*/

int main(void) {
	int *input = (int *)calloc(3, sizeof(int));

	if (!input)
		return (0);

	for (int i = 0; i < 3; ++i)
		scanf("%d", input + i);

	int theatreSquareArea = input[0] / input[2];
	if (input[0] % input[2] != 0)
		++theatreSquareArea;
	int flagStoneArea = input[1] / input[2];
	if (input[1] % input[2] != 0)
		++flagStoneArea;

	unsigned long long result = (unsigned long long)theatreSquareArea * (unsigned long long)flagStoneArea;

	printf("%lld\n", result);

	free(input);
	return (0);
}
