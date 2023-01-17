#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	unsigned short a, b;
	scanf("%hu %hu", &a, &b);
	printf("%hu", a << b);
	return 0;
}