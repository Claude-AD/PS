#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, i = 0, sum = 0; // n�� �Է¹��� ����, i�� sum�� ���ʴ�� ���ذ� ����
	scanf("%d", &n);

	while (sum < n) {
		i++;
		sum += i;
	}
	printf("%d\n", i);
	return 0;
}