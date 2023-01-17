#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	unsigned char a, b;
	scanf("%hhu %hhu", &a, &b);
	printf("%hhu", a || b);
	return 0;
}