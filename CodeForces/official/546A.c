#include <stdio.h>
#include <stdlib.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/546/A
        I am happy to code :)
*/

int main(void) {
	int *input = (int *)calloc(3, sizeof(int));
	if (!input)
		return (0);
	for (int i = 0; i < 3; ++i)
		scanf("%d", input + i);

	int cost = 0;
	int borrow = 0;
	int index = 2;
	cost += input[0];
	for (int i = 1; i < input[2]; ++i)
		cost += (index++) * input[0];

	borrow = (input[1] - cost) * -1;
	if (borrow < 0)
		borrow *= 0;
	printf("%d\n", borrow);
	free(input);
	return (0);
}
