#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	unsigned char n;
	scanf("%hhu", &n);

	for (int i = 0; i <= n; i++) {
		printf("%d\n", i);
	}
	return 0;
}