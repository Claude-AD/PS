#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	unsigned int a, b;
	scanf("%u %u", &a, &b);
	printf("%u", a % b);
	return 0;
}