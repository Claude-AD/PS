#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void change(int& n) {
	if (n == 0) n = 1;
	else n = 0;
}

int main(void) {
	int board[19][19] = {};
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			scanf("%d", &board[i][j]);
		}
	}
	
	unsigned char n;
	scanf("%hhu", &n);
	for (int i = 0; i < n; i++) {
		unsigned char x, y;
		scanf("%hhu %hhu", &x, &y);

		for (int j = 0; j < 19; j++) {
			change(board[x - 1][j]);
		}
		for (int i = 0; i < 19; i++) {
			change(board[i][y - 1]);
		}
	}

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}