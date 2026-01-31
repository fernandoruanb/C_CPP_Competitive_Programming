#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/1535/A
        I am happy to code :)
*/

int main(void) {
	int input;

	scanf("%d", &input);

	int **array = (int **)calloc(input, sizeof(int *));
	if (!array)
		return (0);

	int index = 0;
	while (index < input) {
		array[index] = (int *)calloc(4, sizeof(int));
		if (!array[index]) {
			while (index--)
				free(array[index]);
			free(array);
			return (0);
		}
		for (int i = 0; i < 4; ++i)
			scanf("%d", &array[index][i]);
		++index;
	}

	int firstWinner = 0;
	int firstLoser = 0;
	int secondWinner = 0;
	int secondLoser = 0;

	index = 0;

	while (index < input) {
		if (array[index][0] > array[index][1]) {
			firstWinner = array[index][0];
			firstLoser = array[index][1];
		} else {
			firstWinner = array[index][1];
			firstLoser = array[index][0];
		}
		if (array[index][2] > array[index][3]) {
			secondWinner = array[index][2];
			secondLoser = array[index][3];
		} else {
			secondWinner = array[index][3];
			secondLoser = array[index][2];
		}
		if (firstWinner < secondLoser || secondWinner < firstLoser)
			write(1, "NO\n", 3);
		else
			write(1, "YES\n", 4);
		++index;
	}

	index = 0;
	while (index < input) {
		free(array[index]);
		++index;
	}
	free(array);
	return (0);
}
