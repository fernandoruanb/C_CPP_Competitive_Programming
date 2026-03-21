#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_LEN 1001

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/1873/A
        I am happy to code :)
*/

int main(void) {
	int input;

	scanf("%d", &input);

	if (!input || input < 1 || input > 1000)
		return (0);
	
	char results[MAX_LEN];
	int sum = 0;
	int counter = 0;
	int length;

	for (int i = 0; i < input; ++i) {
		scanf("%d", &length);
		if (length < 2 || length > 50)
			return (0);
		int *numbers = (int *)calloc(length, sizeof(int));
		if (!numbers)
			return (0);

		for (int i = 0; i < length; ++i)
			scanf("%d", numbers + i);

		for (int i = 0; i < length; ++i)
			sum += numbers[i];

		if ((sum & 1) == 0)
			results[counter++] = 'Y';
		else
			results[counter++] = 'N';
		sum = 0;
		free(numbers);	
	}
	results[counter] = '\0';
	for (int i = 0; i < counter; ++i) {
		if (results[i] == 'Y')
			write(1, "YES\n", 4);
		else if (results[i] == 'N')
			write(1, "NO\n", 3);
	}
	return (0);
}
