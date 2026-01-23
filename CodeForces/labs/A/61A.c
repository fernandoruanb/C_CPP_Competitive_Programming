#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LEN 102

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/61/A
        I am happy to code :)
*/

static ssize_t strLen(char *str) {
	ssize_t length = 0;
	while (*(str + length) != '\n' && *(str + length) != '\0')
		++length;
	return (length);
}

static bool isOnlyBinaries(char *input) {
	while (*input) {
		if (*input != '0' && *input != '1' && *input != '\n')
			return (false);
		++input;
	}
	return (true);
}

static void sumBinaries(char *a, char *b) {
	//bool carry = false;
	ssize_t length = strLen(a) - 1;
	char buffer[MAX_LEN];
	int index = 0;

	while (length >= 0) {
		if (index + 1 == INT_MAX)
			break ;
		//printf("a[length]: %c | b[length]: %c\n", a[length], b[length]);
		if ((a[length] == '1' && b[length] == '1') || (b[length] == '1' && a[length] == '1')) {
			/*if (carry) {
				buffer[index++] = '1';
				carry = true;
			}
			else {
				buffer[index++] = '0';
				carry = true;
			}*/
			buffer[index++] = '0';
		} else if ((a[length] == '0' && b[length] == '1') || (b[length] == '0' && a[length] == '1')) {
			/*if (carry) {
				carry = true;
				buffer[index++] = '0';
			}
			else
				buffer[index++] = '1';*/
			buffer[index++] = '1';
		} else if ((a[length] == '0' && b[length] == '0') || (b[length] == '0' && a[length] == '0')) {
			/*if (carry) {
				buffer[index++] = '1';
				carry = false;
			}
			else
				buffer[index++] = '0';*/
			buffer[index++] = '0';
		} else if ((a[length] == '1' && b[length] == '0') || (b[length] == '1' && a[length] == '0')) {
			/*if (carry) {
				carry = true;
				buffer[index++] = '0';
			} else
				buffer[index++] = '1';*/
			buffer[index++] = '1';
		}
		//printf("buffer: %s\n", buffer);
		--length;
	}
	/*if (carry) {
		buffer[index++] = '1';
		carry = false;
	}*/
	while (index--) 
		write(1, &buffer[index], 1);
	write(1, "\n", 1);
}

static char *fixBinaries(char *a, char *b) {
	ssize_t length_a = strLen(a);
	ssize_t length_b = strLen(b);

	if (length_a == length_b)
		return (NULL);
	else if (length_a > length_b) {
		int	index = 0;
		char *newBuffer = (char *)calloc(1, strLen(a) + 1);
		if (!newBuffer)
			return (NULL);
		while (length_a > length_b) {
			newBuffer[index] = '0';
			++index;
			--length_a;
		}
		while (*b != '\0' && *b != '\n') {
			newBuffer[index++] = *b;
			++b;
		}
		newBuffer[index] = '\0';
		return (newBuffer);
	} else if (length_a < length_b) {
		int	index = 0;
		char *newBuffer = (char *)calloc(1, strLen(b) + 1);
		if (!newBuffer)
			return (NULL);
		while (length_b > length_a) {
			newBuffer[index] = '0';
			++index;
			--length_b;
		}
		while (*a != '\0' && *a != '\n') {
			newBuffer[index] = *a;
			++a;
		}
		newBuffer[index] = '\0';
		return (newBuffer);
	}
	return (NULL);
}

int main(void) {
	char a[MAX_LEN];
	char b[MAX_LEN];
	int flagA = false;
	int flagB = false;

	fgets(a, MAX_LEN, stdin);
	if (a[0] == '\n' || a[0] == '\0' || !isOnlyBinaries(a)) {
		//write(2, "Error\n", 6);
		return (0);
	}
	fgets(b, MAX_LEN, stdin);
	if (b[0] == '\n' || a[0] == '\0' || !isOnlyBinaries(b)) {
		//write(2, "Error\n", 6);
		return (0);
	}
	if (strLen(a) > strLen(b))
		flagA = true;
	else if (strLen(a) < strLen(b))
		flagB = true;
	char *new = fixBinaries(a, b);
	if (new && flagA)
		sumBinaries(new, b);
	else if (new && flagB)
		sumBinaries(a, new);
	else if (!new)
		sumBinaries(a, b);
	if (flagA)
		free(new);
	else if (flagB)
		free(new);
	return (0);
}
