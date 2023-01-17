#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	unsigned char a;
	scanf("%hhu", &a);
	printf("%hhu", !a);
	return 0;
}