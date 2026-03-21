#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LEN 10002

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/339/A
        I am happy to code :)
*/

static int numberConversor(char *n, bool *err) {
	long result = 0;
	long signal = 1;

	while (*n == ' ' || *n == '\t' || *n == '\n' || *n == '\f' || *n == '\v'
		|| *n == '\a' || *n == '\b' || *n == '\r')
		++n;
	while (*n == '+' || *n == '-') {
		if (*n == '-')
			signal *= -1;
		++n;
	}
	while (*n >= '0' && *n <= '9') {
		result *= 10;
		result += *n - '0';
		if (result > INT_MAX || (result * signal) < INT_MIN) {
			*err = false;
			return (0);
		}
		++n;
	}
	return ((int)result * signal);
}

static void bubbleSort(int *numbers, int input) {
	int tmp;

	for (int counter = input - 1; counter > 0; --counter) {
		for (int index = 0; index < counter; ++index) {
			if (numbers[index] > numbers[index + 1]) {
				tmp = numbers[index];
				numbers[index] = numbers[index + 1];
				numbers[index + 1] = tmp;
			}
		}
	}
}

static void printNumbers(int *numbers, int counter) {
	int index = 0;
	while (index < counter) {
		if (index + 1 == counter)
			printf("%d\n", numbers[index]);
		else
			printf("%d+", numbers[index]);
		++index;
	}
}

static void getAndPrintNumbers(char *input) {
	char buffer[MAX_LEN];
	int *numbers = (int *)calloc(1, sizeof(int));
	int n;
	int check;
	int counter = 0;
	int index = 0;
	bool err = false;
	int *p;

	while (*input) {
		if (*input >= '0' && *input <= '9')
			buffer[index++] = *input;
		else if (*input == '+' || *(input + 1) == '\0') {
			++counter;
			p = (int *)realloc(numbers, counter * sizeof(int));
			if (!p) {
				free(numbers);
				return ;
			}
			numbers = p;
			p = NULL;
			n = numberConversor(buffer, &err);
			if (err) {
				free(numbers);
				return ;
			}
			numbers[counter - 1] = n;
			check = sizeof(buffer);
			while (check--)
				buffer[check] = '\0';
			index = 0;
		} else {
			free(numbers);
			return ;
		}
		++input;
	}
	bubbleSort(numbers, counter);
	printNumbers(numbers, counter);
	free(numbers);
}

int main(void) {
	char input[MAX_LEN];

	fgets(input, MAX_LEN, stdin);
	if (input[0] == '\n' || input[0] == '\0')
		return (0);
	getAndPrintNumbers(input);
	return (0);
}
