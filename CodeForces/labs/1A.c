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

int main(void) {
	int *input = (int *)calloc(3, sizeof(int));

	if (!input)
		return (0);

	for (int i = 0; i < 3; ++i)
		scanf("%d", input + i);

	int theatreSquareArea = input[0] * input[1]; // m^2
	int flagStoneArea = input[2] * input[2]; // m^2
	int counter = 0;

	while (theatreSquareArea > flagStoneArea) {
		flagStoneArea *= 2;
		++counter;
	}
	printf("%d\n", counter);
	free(input);
	return (0);
}
