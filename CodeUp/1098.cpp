#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int h, w, n, l, d, x, y;
	
	// 세로 h, 가로 w인 격자판 2차원 배열 동적 생성
	scanf("%d %d", &h, &w);
	int** board = new int*[h];
	for (int i = 0; i < h; i++)
		board[i] = new int[w];

	// 2차원 배열 모든 원소 0으로 초기화
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			board[i][j] = 0;
		}
	}

	// 막대의 개수, 길이, 방향, 좌표 입력받고 격자판에 배치
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

	// 2차원 배열 모든 원소 출력
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	
	// 동적 할당한 2차원 배열 해제
	for (int i = 0; i < h; i++)
		delete[] board[i];
	delete[] board;
	return 0;
}