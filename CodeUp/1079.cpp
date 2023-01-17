#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	char alpha = ' ';
	while (alpha != 'q') {
		scanf("%c ", &alpha);
		printf("%c\n", alpha);
	}
	return 0;
}