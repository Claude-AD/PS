#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int idF, idB;
	scanf("%d-%d", &idF, &idB); // scanf ���� ������ ��, ���ڿ��� %d-%d ó�� �Է� �޴� �͵� ���̿�
							// ���ڸ� �־ ������ ������ �� ����. �������� ���ڿ����� �𸣱� ����
	printf("%06d%07d", idF, idB);
	return 0;
}