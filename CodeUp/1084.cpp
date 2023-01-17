#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	unsigned char r, g, b;
	int count = 0;
	scanf("%hhu %hhu %hhu", &r, &g, &b);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < g; j++) {
			for (int k = 0; k < b; k++) {
				printf("%d %d %d\n", i, j, k);
				count++;
			}
		}
	}
	printf("%d\n", count);
	return 0;
}