#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// XOR ��� - A�� B�� ���� 0(����)�� 1(��)�� ǥ�� �׷����� �����ϱ�
int main(void) {
	unsigned char a, b;
	scanf("%hhu %hhu", &a, &b);
	printf("%hhu", (!a && b) || (a && !b));
	return 0;
}