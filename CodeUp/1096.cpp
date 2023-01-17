#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int board[19][19] = {};
	
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		unsigned char x, y;
		scanf("%hhu %hhu", &x, &y);
		
		if (board[x - 1][y - 1] == 0) {
			board[x - 1][y - 1]++;
		}
		else continue;
	}
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	return 0;
}