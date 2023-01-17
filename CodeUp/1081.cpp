#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	unsigned char n, m;
	scanf("%hhu %hhu", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			printf("%d %d\n", i, j);
		}
	}
	return 0;
}