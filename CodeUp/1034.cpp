#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	// C���� �ҽ� �ڵ� �ۼ� �� 0���� �����ϴ� ���� 8������ �νĵȴ�. 
	// int a = 013; -> 10���� 11�� ���� ��
	int n;
	scanf("%o", &n);
	printf("%d", n);
	return 0;
}