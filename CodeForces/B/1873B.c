#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/1873/B
        I am happy to code :)
*/

int main(void) {
	int input, length;

	scanf("%d", &input);

	if (!input || input < 1 || input > 10000)
		return (0);

	int min = INT_MAX;
	int index = 0;
	int *numbers = NULL;
	unsigned long long result = 1;
	unsigned long long counter = 0;
	unsigned long long *final = (unsigned long long *)calloc(10002, sizeof(unsigned long long));

	for (int i = 0; i < input; ++i) {
		scanf("%d", &length);
		numbers = (int *)calloc(length, sizeof(int));
		if (!numbers)
			return (0);
		for (int i = 0; i < length; ++i) {	
			scanf("%d", numbers + i);
			if (min > numbers[i]) {
				min = numbers[i];
				index = i;
			}
		}
		for (int i = 0; i < length; ++i) {
			if (i != index)
				result *= numbers[i];
			if (i == index) 
				result *= (numbers[i] + 1);
		}
		final[counter++] = result;
		result = 1;
		index = 0;
		min = INT_MAX;
		free(numbers);
		numbers = NULL;
	}
	for (int i = 0; i < counter; ++i)
		printf("%lld\n", final[i]);
	free(final);
	final = NULL;
	return (0);
}
