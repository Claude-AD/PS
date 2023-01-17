#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	unsigned char n;
	unsigned short sum = 0;
	scanf("%hhu", &n);

	for (int i = 0; i <= n; i++) {
		if (i % 2 == 0) sum += i;
	}
	printf("%hu\n", sum);
	return 0;
}