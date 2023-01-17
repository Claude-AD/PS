#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char alpha;
	scanf("%c", &alpha);

	int n = 97;
	do {
		printf("%c ", n);
		n++;
	} while (n <= alpha);

	printf("\n");
	return 0;
}