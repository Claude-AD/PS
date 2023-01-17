#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	unsigned char n;
	scanf("%hhu", &n);

	for (int i = 1; i <= n; i++) {
		if (i % 3 == 0) printf("X ");
		else printf("%d ", i);
	}
	printf("\n");
	return 0;
}