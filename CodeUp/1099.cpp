#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	// 2���� �迭 �̷� �Է¹���
	int maze[10][10] = {};
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &maze[i][j]);

			// �Է� ���� ����
			if (maze[i][j] != 0 && maze[i][j] != 1 && maze[i][j] != 2) {
				printf("Wrong Input!!\n");
				return 0;
			}
		}
	}

	// ���̰� �̵�
	int antPosX = 1, antPosY = 1;
	while (1) {
		// ���̰� ���̸� �����ų�
		// ���� ��ġ�� �������� 1�� �����ְų� �� �������� ��, �Ʒ��� 1�� �����ְų� �� �Ʒ���
		if (maze[antPosY][antPosX] == 2 ||
			((maze[antPosY][antPosX + 1] == 1 || antPosX == 9) &&
			(maze[antPosY + 1][antPosX] == 1 || antPosY == 9))) {
			maze[antPosY][antPosX] = 9; // ������ �̵���� ǥ�� ��
			break; // �� ���� �ӹ���
		}
		
		maze[antPosY][antPosX] = 9; // ������ �̵���� ǥ��

		// ���� ��ġ�� �������� ����������, �Ʒ��� �շ��ִٸ�
		if (maze[antPosY][antPosX + 1] == 1 || antPosX == 9)
			antPosY++; // �Ʒ��� �̵�
		else // �������� �շ��ִٸ�
			antPosX++; // ���������� �̵�
	}


	// 2���� �迭 ���
	printf("\n\n");
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d ", maze[i][j]);
		}
		printf("\n");
	}
	return 0;
}