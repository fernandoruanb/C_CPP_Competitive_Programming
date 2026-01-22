#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/405/A
        I am happy to code :)
*/

static void bubble_sort(int *numbers, int input) {
	int tmp;

	for (int counter = input - 1; counter > 0; --counter) {

		for (int index = 0; index < counter; ++index) {

			if (numbers[index] > numbers[index + 1]) {
				tmp = numbers[index];
				numbers[index] = numbers[index + 1];
				numbers[index + 1] = tmp;
			}
		}
	}
}

/*
	BUBBLE SORT EXPLANATION

	counter must need to be the quantity of input numbers minus 1 because we need to set index format
	index will be always less than the counter. For each cycle, at less one number is in the correct order
	if the number in the position index is greater than the number in next position we swap them to put in
	correct order
*/

int main(void) {
	int input;

	scanf("%d", &input);

	if (!input || input < 1 || input > 100)
		return (0);

	int *numbers = (int *)calloc(input, sizeof(int));

	if (!numbers)
		return (0);

	for (int i = 0; i < input; ++i)
		scanf("%d", numbers + i);

	bubble_sort(numbers, input);
	for (int i = 0; i < input; ++i) {
		if (i + 1 == input)
			printf("%d\n", numbers[i]);
		else
			printf("%d ", numbers[i]);
	}
	free(numbers);
	return (0);
}
