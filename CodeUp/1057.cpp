#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// https://codeup.kr/upload/pimg6173_1.png
int main(void) {
	unsigned char a, b;
	scanf("%hhu %hhu", &a, &b);
	printf("%hhu", (!a && !b) || (a && b));
	return 0;
}