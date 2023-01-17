#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		else printf("%d\n", n);
	}
	return 0;
}