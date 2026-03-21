#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/509/A
        I am happy to code :)
*/

static void putNumber(int n) {
	char digit;

	if (n >= 10)
		putNumber(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

int main(void) {
	int input;

	scanf("%d", &input);

	if (input == 1) {
		putNumber(1);
		write(1, "\n", 1);
		return (0);
	}

	int **array = (int **)calloc(input, sizeof(int *));
	if (!array)
		return (0);
	for (int i = 0; i < input; ++i) {
		array[i] = (int *)calloc(input, sizeof(int));
		if (!array[i]) {
			while (i--)
				free(array[i]);
			free(array);
			return (0);
		}
	}

for (int i = 0; i < input; ++i) {
	array[i][0] = 1;
	array[0][i] = 1;
}

for (int i = 1; i < input; ++i) {
    for (int j = 1; j < input; ++j) 
          array[i][j] = array[i - 1][j] + array[i][j - 1];
}

	putNumber(array[input - 1][input - 1]);
	write(1, "\n", 1);
	for (int i = 0; i < input; ++i)
		free(array[i]);
	free(array);
	return (0);
}
