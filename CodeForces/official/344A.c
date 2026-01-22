#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_LEN 12

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/344/A
        I am happy to code :)
*/

static int checkOrder(char *input, int index) {
	static char last = '\0';
	static bool inGroup = false;
	static int groups = 0;

	if (last == '\0') {
		last = *(input + 1);
		inGroup = true;
		++groups;
	}
	else if ((last == '1' && *input == '0' || last == '0' && *input == '1') && !inGroup) {
		inGroup = true;
		++groups;
		last = *(input + 1);
	} else if ((last == '1' && *input == '0' || last == '0' && *input == '1') && inGroup) {
		last = *(input + 1);
	} else if ((last == '1' && *input == '1') || (last == '0' && *input == '0') && inGroup) {
		inGroup = true;
		++groups;
		last = *(input + 1);
	} else if ((last == '1' && *input == '1' || (last == '0' && *input == '0') && !inGroup)) {
		++groups;
		last = *(input + 1);
	}
	//printf("last: %c\ngroups: %d\no último: %c\n", last, groups, *(input + 1));
	if (index == 0)
		return (groups);
	return (0);
}

int main(void) {
	int input;

	scanf("%d", &input);

	if (!input || input < 1 || input > 1000000)
		return (0);

	char room[MAX_LEN];
	int result = 0;
	int check;

	while (input--) {
		check = sizeof(room);
		while (check--)
			room[check] = '\0';
		scanf("%s", room);
		if (room[0] == '\0' || room[0] == '\n')
			return (0);
		result += checkOrder(room, input);	
	}
	printf("%d\n", result);
	return (0);
}
