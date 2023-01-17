#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	unsigned char a, b, c;
	int day = 1;
	scanf("%hhu %hhu %hhu", &a, &b, &c);

	while (day % a != 0 || day % b != 0 || day % c != 0) day++;
	printf("%d\n", day);
	return 0;
}