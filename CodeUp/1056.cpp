#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// XOR 출력 - A와 B에 대해 0(거짓)과 1(참)로 표를 그려놓고 생각하기
int main(void) {
	unsigned char a, b;
	scanf("%hhu %hhu", &a, &b);
	printf("%hhu", (!a && b) || (a && !b));
	return 0;
}