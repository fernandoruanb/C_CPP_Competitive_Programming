#include <stdio.h>
#include <unistd.h>

static void putNumber(int n) {
	char digit;

	if (n >= 10)
		putNumber(n / 10);
	digit = (n % 10) + '0';
	write(1, &digit, 1);
}

static void printPyramid(int n) {
	int width = n - 2;
	int height = n - 2;
	int middle = n - 1;
	int index = 0;
	int tmp = 0;
	char digit;

	while (index <= height) {
		tmp = 0;
		if (index == 0 || index == height) {
			while (tmp <= n) {
				putNumber(n);
				if (tmp != n)
					write(1, " ", 1);
				else
					write(1, "\n", 1);
				++tmp;
			}
		}
		++index;
	}
}

int main(void) {
	unsigned int n;

	scanf("%u", &n);

	if (n < 1 || n > 1000)
		return (0);
	printPyramid(n);
	return (0);
}
