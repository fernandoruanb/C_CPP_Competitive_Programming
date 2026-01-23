#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_LEN 102

/*
        Author: Fernando Ruan
        Profile: https://codeforces.com/profile/fruan-ba
        Country: Brazil
        ChallengeLink: https://codeforces.com/problemset/problem/263/A
        I am happy to code :)
*/

static void putNumber(int n) {
	char digit;

	if (n >= 10)
		putNumber(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);	
}

static void checkBeautifulMatrix(int x, int y) {
	int target_x = 2;
	int target_y = 2;
	int mov_x = 0;
	int mov_y = 0;

	/* Sequence is X
		     n0 n1 n2 n3 n4 -> numbers 
	sequence 0 -> 0 0 0 0 0
	sequence 1 -> 0 0 1 0 0
	sequence 2 -> 0 0 0 0 0 -> 2 and 2 (x, y) is the "beautiful matrix"

	*/

	if (x > target_x) {
		while (x-- > target_x)
			++mov_x;
	} else if (x < target_x) {
		while (x++ < target_x)
			++mov_x;
	}

	if (y > target_y) {
		while (y-- > target_y)
			++mov_y;
	} else if (y < target_y) {
		while (y++ < target_y)
			++mov_y;
	}
	int result = mov_x + mov_y;
	putNumber(result);
	write(1, "\n", 1);
}

static bool isValid(char *str, int sequence) {
	static int index = 0;
	static int x = 0;
	static int y = 0;
	int	numbers = 0;

	while (*str) {
		if (*str >= '0' && *str <= '9') {
			if (*str != '0' && *str != '1')
				return (false);
			if (*str == '1') {
				x = sequence;
				y = numbers;
				++index;
			}
			++numbers;
		}
		++str;
	}
	if ((sequence == 4 && index != 1) || index > 1 || numbers != 5)
		return (false);
	if (sequence == 4)
		checkBeautifulMatrix(x, y);
	return (true);
}

int main(void) {
	char input[MAX_LEN][MAX_LEN];
	int index = 0;

	while (index < 5) {
		fgets(input[index], MAX_LEN, stdin);
		if (!isValid(input[index], index)) {
			write(2, "Error\n", 6); 
			return (0);
		}
		++index;
	}
	return (0);
}
