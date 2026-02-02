#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/577/A
        I am happy to code :)
*/

static bool is_prime(int x) {
	if (x < 1)
		return (false);

	int starter = 2;

	while (starter * starter <= x) {
		if (x % starter == 0)
			return (false);
		++starter;
	}
	return (true);
}

static void putNumber(int n) {
	char digit;

	if (n >= 10)
		putNumber(n / 10);

	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

int main(void) {
	unsigned long long n, x;

	scanf("%lld %lld", &n, &x);

	/*int **array = (int **)calloc(n, sizeof(int *));
	if (!array)
		return (0);
	for (int i = 0; i < n; ++i) {
		array[i] = (int *)calloc(n, sizeof(int));
		if (!array[i]) {
			while (i--)
				free(array[i]);
			free(array);
			return (0);
		}
	}*/

	int counter = 0;
	unsigned long long result;
	unsigned long long target = 0;

	/*
		In that problem, first we need to discover if i can divide the x number. In other words, if x is
		multiple of i. Then, we try to find if the j position multipliying i gets x number. That is the
		condition to finish that challenge
	*/

	for (unsigned long long i = 0; i < n; ++i) {
		if (x % (i + 1) == 0) {
			for (int j = 0; j < n; ++j) {
				if (x == ((i + 1) * (j + 1))) {
					++counter;
				}
			}
		}
	}

	putNumber(counter);
	write(1, "\n", 1);

	/*for (int i = 0; i < n; ++i)
		free(array[i]);
	free(array);*/

	return (0);
}
