#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_LEN 1002

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/43/A
        I am happy to code :)
*/

static void putStr(char *str) {
	char digit;

	while (*str) {
		digit = *str;
		write(1, &digit, 1);
		++str;
	}
	write(1, "\n", 1);
}

static int strCmp(char *s1, char *s2) {
	unsigned long long index = 0;

	while (*(s1 + index) && *(s2 + index)) {
		if (*(s1 + index) != *(s2 + index))
			return (*(s1 + index) - *(s2 + index));
		++index;
	}
	return (*(s1 + index) - *(s2 + index));
}

static size_t strLen(char *s) {
	size_t length = 0;
	while (*(s + length))
		++length;
	return (length);
}

static char *strDup(char *s) {
	size_t length = strLen(s);
	char *buffer = calloc(1, sizeof(length));
	int index = 0;

	if (!buffer)
		return (NULL);
	while (*(s + index)) {
		buffer[index] = *(s + index);
		++index;
	}
	buffer[index] = '\0';
	return (buffer);
}

int main(void) {
	int input;

	scanf("%d", &input);

	if (!input || input < 1 || input > 100)
		return (0);

	/* we need to allocate enough memory to store everything we need, the box of strings and the length will be
	  the same
	*/

	char **array = (char **)calloc(input, sizeof(char *));
	if (!array)
		return (0);

	/*
		In the first allocation, we only allocate the box necessary to store strings, but we need to
		allocate memory for each string individually too
	*/

	for (int i = 0; i < input; ++i) {
		array[i] = (char *)calloc(6, sizeof(char *));
		if (!array[i]) {
			while (i--)
				free(array[i]);
			free(array);
			return (0);
		}
	}

	for (int i = 0; i < input; ++i)
		scanf("%s", array[i]);

	/*for (int i = 0; i < input; ++i)
		printf("%s\n", array[i]);*/

	char *team_a = NULL;
	char *team_b = NULL;
	int counter_a = 0;
	int counter_b = 0;

	if (input == 1)
		printf("%s\n", array[0]);
	else {
		for (int i = 0; i < input; ++i) {
			if (!team_a) {
				team_a = array[i];
				++counter_a;
			}
			else if (!team_b && strCmp(team_a, array[i])) {
				team_b = array[i];
				++counter_b;
			}
			else if (team_a && !strCmp(team_a, array[i]))
				++counter_a;
			else if (team_b && !strCmp(team_b, array[i]))
				++counter_b;
		}
		if (counter_a > counter_b)
			putStr(team_a);
		else
			putStr(team_b);
		//printf("counter_a: %d\ncounter_b: %d\n", counter_a, counter_b);
	}

	// Clean step, we need to clean every string and also the box that we used to store them
	for (int i = 0; i < input; ++i)
		free(array[i]);
	free(array);
	team_a = NULL;
	team_b = NULL;
	return (0);
}
