#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_LEN 10002

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/1673/A
        I am happy to code :)
*/

static int strLen(char *buffer) {
	int length = 0;
	while (*(buffer + length))
		++length;
	return (length);
}

static void printResult(char *results) {
	while (*results) {
		if (*results == 'Y')
			write(1, "YES\n", 4);
		else
			write(1, "NO\n", 3);
		++results;
	}
}

static void checkLuckyTicket(char *buffer, int input) {
	int length = strLen(buffer);
	static char results[MAX_LEN];
	int *ticket = (int *)calloc(length, sizeof(int));
	int index = 0;
	static int counter = 0;

	while (*buffer >= '0' && *buffer <= '9') {
		ticket[index++] = *buffer - '0';
		++buffer;
	}

	if ((ticket[0] + ticket[1] + ticket[2]) == (ticket[3] + ticket[4] + ticket[5]))
		results[counter++] = 'Y';
	else
		results[counter++] = 'N';
	if (input == 0) {
		results[counter] = '\0';
		printResult(results);
	}
	free(ticket);
}

static bool areOnlyNumbers(char *buffer) {
	while (*buffer != '\0' || *buffer == '\n') {
		if (*buffer < '0' || *buffer > '9')
			return (false);
		++buffer;
	}
	return (true);
}

int main(void) {
	int input;

	scanf("%d", &input);

	if (input < 1 || input > 1000)
		return (0);

	char buffer[MAX_LEN];
	int check;

	while (input--) {
		check = sizeof(buffer);
		while (check)
			buffer[check--] = '\0';
		scanf("%s", buffer);
		if (buffer[0] == '\0' || buffer[0] == '\n')
			return (0);
		if (!areOnlyNumbers(buffer))
			return (0);
		checkLuckyTicket(buffer, input);
	}
	return (0);
}
