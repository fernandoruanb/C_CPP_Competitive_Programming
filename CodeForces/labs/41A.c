#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_LEN 102

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/41/A
        I am happy to code :)
*/

static ssize_t strLen(char *str) {
	ssize_t	length = 0;
	while (*(str + length))
		++length;
	return (length);
}

/*static ssize_t strCmp(char *a, char *b) {
	ssize_t index = 0;

	while (*(a + index) && *(b + index)) {
		if (*(a + index) != *(b + index))
			return (*(a + index) - *(b + index));
		++index;
	}
	return (*(a + index) - *(b + index));
}*/

static char *prepareString(char *str) {
	ssize_t counter = 0;
	char *new_str = (char *)malloc(MAX_LEN * sizeof(char));

	if (!new_str)
		return (NULL);
	while (*str) {
		if (*str == '\n')
			break ;
		new_str[counter++] = *str;
		++str;
	}
	new_str[counter] = '\0';
	return (new_str);
}

static void reverseStringCheck(char *new_a, char *new_b) {
	ssize_t length = strLen(new_b);
	ssize_t	initial_a = strLen(new_a);
	bool flag = false;

	if (initial_a != length)
		flag = true;

	while (length - 1 >= 0 && *new_a) {
		if (*new_a != new_b[length - 1]) {
			flag = true;
			break ;
		}
		++new_a;
		--length;
	}
	if (!flag && length == 0)
		write(1, "YES\n", 4);
	else
		write(1, "NO\n", 3);
	return ;
}

static void check_reverse_a_b(char *a, char *b) {

	char *new_a = prepareString(a);
	char *new_b = prepareString(b);

	if (!new_a || !new_b) {
		if (new_a)
			free(new_a);
		if (new_b)
			free(new_b);
		return ;
	}
	reverseStringCheck(new_a, new_b);
	free(new_a);
	free(new_b);
	return ;
}

int main(void) {
	char a[MAX_LEN];
	char b[MAX_LEN];

	fgets(a, MAX_LEN, stdin);
	fgets(b, MAX_LEN, stdin);
	if (a[0] == '\n' || a[0] == '\0' || b[0] == '\n' || b[0] == '\0') {
		//write(2, "Empty\n", 6);
		return (0);
	}
	/*if (strLen(a) != strLen(b)) {
		//write(2, "Mismatch\n", 9);
		return (0);
	}*/
	check_reverse_a_b(a, b);
	return (0);
}
