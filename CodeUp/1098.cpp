#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int h, w, n, l, d, x, y;
	
	// ���� h, ���� w�� ������ 2���� �迭 ���� ����
	scanf("%d %d", &h, &w);
	int** board = new int*[h];
	for (int i = 0; i < h; i++)
		board[i] = new int[w];

	// 2���� �迭 ��� ���� 0���� �ʱ�ȭ
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			board[i][j] = 0;
		}
	}

	// ������ ����, ����, ����, ��ǥ �Է¹ް� �����ǿ� ��ġ
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d %d", &l, &d, &x, &y);
		if (d == 0) {
			for (int j = 0; j < l; j++) {
				board[x - 1][y - 1 + j] = 1;
			}
		}
		else {
			for (int j = 0; j < l; j++) {
				board[x - 1 + j][y - 1] = 1;
			}
		}
	}
	printf("\n");

	// 2���� �迭 ��� ���� ���
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	
	// ���� �Ҵ��� 2���� �迭 ����
	for (int i = 0; i < h; i++)
		delete[] board[i];
	delete[] board;
	return 0;
}