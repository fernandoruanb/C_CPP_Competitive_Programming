#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/1512/A
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
	int cases;

	scanf("%d", &cases);

	if (cases < 1 || cases > 100)
		return (0);

	int people;
	int *file = NULL;
	int *answers = (int *)calloc(100, sizeof(int));

	if (!answers)
		return (0);

	int check = 0;

	for (int i = 0; i < cases; ++i) {
		scanf("%d", &people);
		if (people < 3 || people > 100)
			return (0);
		file = (int *)calloc(people, sizeof(int));
		if (!file)
			return (0);
		for (int i = 0; i < people; ++i) {
			scanf("%d", file + i);
		}

		int a = 0;
		int b = 0;
		int counter_A = 0;
		int counter_B = 0;

		for (int i = 0; i < people; ++i) {
			if (a == 0) {
				a = file[i];
				++counter_A;
			} else if (a == file[i])
				++counter_A;
			else if (b == 0) {
				b = file[i];
				++counter_B;
			} else 
				++counter_B;
		}
		if (counter_A > counter_B) {
			for (int i = 0; i < people; ++i) {
				if (file[i] == b) {
					answers[check++] = i + 1;
					break ;
				}
			}
		} else {
			for (int i = 0; i < people; ++i) {
				if (file[i] == a) {
					answers[check++] = i + 1;
					break ;
				}
			}
		}
		free(file);
	}
	int index = 0;
	while (index < check) {
		putNumber(answers[index++]);
		write(1, "\n", 1);
	}
	free(answers);
	return (0);
}
