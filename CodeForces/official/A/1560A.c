#include <stdio.h>
#include <stdlib.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/1560/A
        I am happy to code :)
*/

int main(void) {
	int input;

	scanf("%d", &input);

	if (!input || input < 0 || input > 1000)
		return (0);
	int *room = (int *)calloc(input, sizeof(int));
	if (!room)
		return (0);
	for (int i = 0; i < input; ++i) {
		scanf("%d", room + i);
	}
	int num = 0;
	for (int i = 0; i < input; ++i) {
		int target = room[i];
		num = 0;
		while (target) {
			++num;
			if (num % 3 != 0 && num < 10)
				--target;
			else if (num >= 10) {
				if (num % 10 == 3)
					continue ;
				if (num % 3 != 0)
					--target;
			}
		}
		printf("%d\n", num);
	}
	free(room);
	return (0);
}
