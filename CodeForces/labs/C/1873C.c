#include <stdio.h>
#include <stdlib.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/1873/C
        I am happy to code :)
*/

int main(void) {
	int input;

	scanf("%d", &input);

	if (!input || input < 1 || input > 1000)
		return (0);

	int total = input * 10;

	char **array = (char **)calloc(total, sizeof(char *));
	if (!array)
		return (0);

	for (int i = 0; i < total; ++i) {
		array[i] = (char *)calloc(12, sizeof(char));
		if (!array[i]) {
			while (i--)
				free(array[i]);
			free(array);
			return (0);
		}
	}

	for (int i = 0; i < total; ++i) {
		scanf("%10s", array[i]);
		array[i][10] = '\0';
	}

	int *results = (int *)calloc(total, sizeof(int));
	if (!results) {
		for (int i = 0; i < input; ++i)
			free(array[i]);
		free(array);
		return (0);
	}

	int col = 0;
	int result = 0;
	int row = 0;
	int check = 0;
	int counter = 0;

	for (int i = 0; i < total; ++i) {
		while (array[i][row]) {
			if ((col == 0 || col == 9) && array[i][row] == 'X')
				result += 1;
			else if ((row == 0 || row == 9) && array[i][row] == 'X')
				result += 1;
			else if ((row == 1 || row == 8) && array[i][row] == 'X')
				result += 2;
			else if ((col == 1 || col == 8) && row >= 1 && row <= 8 && array[i][row] == 'X')
				result += 2;
			else if ((col == 2 || col == 7) && row >= 2 && row <= 7 && array[i][row] == 'X')
				result += 3;
			else if ((row == 2 || row == 7) && array[i][row] == 'X')
				result += 3;
			else if ((col == 3 || col == 6) && row >= 3 && row <= 6 && array[i][row] == 'X')
				result += 4;
			else if ((row == 3 || row == 6) && array[i][row] == 'X')
				result += 4;
			else if ((col == 4 || col == 5) && row >= 4 && row <= 5 && array[i][row] == 'X')
				result += 5;
			++row;
		}
		if (((i + 1) % 10) == 0) {
			results[counter++] = result;
			result = 0;
			col = 0;
		} else
			++col;
		row = 0;
	}
	for (int i = 0; i < counter; ++i) 
		printf("%d\n", results[i]);
	
	// final clear

	for (int i = 0; i < total; ++i)
		free(array[i]);
	free(array);
	free(results);
	return (0);
}
