#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	for (int i = 0; i < 3; i++) {
		int n;
		scanf("%d", &n);
		if (n % 2 == 0) printf("even\n");
		else printf("odd\n");
	}
	return 0;
}