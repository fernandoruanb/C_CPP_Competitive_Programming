#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_LEN 10000

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/1742/A
        I am happy to code :)
*/

static bool checkOthers(int *room) {
	for (int i = 0; i < 3; ++i) {
		if (i == 0 && room[0] == room[i + 1] + room[i + 2])
			return (true);
		else if (i == 1 && room[1] == room[i - 1] + room[i + 1])
			return (true);
		else if (i == 2 && room[2] == room[i - 2] + room[i - 1])
			return (true);
	}
	return (false);
}

int main(void) {
	int input;
	char buffer[MAX_LEN];
	scanf("%d", &input);

	if (input < 1 || input > 9261)
		return (0);
	int *room;
	int index = 0;

	while (input--) {
		room = (int *)calloc(3, sizeof(int));
		for (int i = 0; i < 3; ++i)
			scanf("%d", room + i);
		if (checkOthers(room))
			buffer[index++] = '1';
		else
			buffer[index++] = '0';
		free(room);		
		if (index > 9999)
			return (0);
	}
	buffer[index] = '\0';
	index = 0;
	while (buffer[index]) {
		if (buffer[index] == '1')
			write(1, "YES\n", 4);
		else
			write(1, "NO\n", 3);
		++index;
	}
	return (0);
}
