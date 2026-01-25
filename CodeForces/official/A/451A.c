#include <stdio.h>
#include <stdlib.h>

static int min(int a, int b) {
	if (a > b)
		return (b);
	return (a);
}

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/451/A
        I am happy to code :)
*/


int main(void) {
	int *dimensions = (int *)calloc(2, sizeof(int));
	if (!dimensions)
		return (0);
	for (int i = 0; i < 2; ++i)
		scanf("%d", dimensions + i);
	int minimum = min(dimensions[0], dimensions[1]);
	if (minimum & 1) // if you draw the problem on the paper, you will see there is an easy task
		puts("Akshat");
	else
		puts("Malvika");
	free(dimensions);
	return (0);
}
