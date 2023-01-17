#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	// 2차원 배열 미로 입력받음
	int maze[10][10] = {};
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &maze[i][j]);

			// 입력 오류 제어
			if (maze[i][j] != 0 && maze[i][j] != 1 && maze[i][j] != 2) {
				printf("Wrong Input!!\n");
				return 0;
			}
		}
	}

	// 개미가 이동
	int antPosX = 1, antPosY = 1;
	while (1) {
		// 개미가 먹이를 만나거나
		// 현재 위치의 오른쪽이 1로 막혀있거나 맨 오른쪽일 때, 아래가 1로 막혀있거나 맨 아래면
		if (maze[antPosY][antPosX] == 2 ||
			((maze[antPosY][antPosX + 1] == 1 || antPosX == 9) &&
			(maze[antPosY + 1][antPosX] == 1 || antPosY == 9))) {
			maze[antPosY][antPosX] = 9; // 개미의 이동경로 표시 후
			break; // 그 곳에 머무름
		}
		
		maze[antPosY][antPosX] = 9; // 개미의 이동경로 표시

		// 현재 위치의 오른쪽은 막혀있으나, 아래가 뚫려있다면
		if (maze[antPosY][antPosX + 1] == 1 || antPosX == 9)
			antPosY++; // 아래로 이동
		else // 오른쪽이 뚫려있다면
			antPosX++; // 오른쪽으로 이동
	}


	// 2차원 배열 출력
	printf("\n\n");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	return 0;
}