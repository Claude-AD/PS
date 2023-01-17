#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	unsigned char n;
	scanf("%hhu", &n);

	if (90 <= n && n <= 100) printf("A\n");
	else if (70 <= n && n < 90) printf("B\n");
	else if (40 <= n && n < 70) printf("C\n");
	else if (0 <= n && n < 40) printf("D\n");
	else printf("Wrong Input!!\n");

	return 0;
}