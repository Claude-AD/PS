#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	unsigned char n;
	scanf("%hhX", &n);

	for (int i = 1; i < 16; i++) {
		printf("%X*%X=%X\n", n, i, n * i);
	}
	return 0;
}