#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/467/A
        I am happy to code :)
*/

int main(void) {
	int input;

	scanf("%d", &input);

	if (!input || input < 0 || input > 100)
		return (0);
	int *room = NULL;
	int result = 0;
	while (input--) {
		room = (int *)calloc(2, sizeof(int));
		for (int i = 0; i < 2; ++i)
			scanf("%d", room + i);
		if (room[0] + 2 <= room[1])
			++result;
		free(room);
		room = NULL;
	}
	printf("%d\n", result);
	return (0);
}
