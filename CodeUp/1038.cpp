#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	long long a, b, sum; 
	// a�� b�� int�� ������ ���� �ʴ´ٰ� �ؼ� int�� �����ع�����
	// long long ���� sum���� ���� ���� �̹� �����÷ο� �Ǿ�����Ƿ� �ǹ̰� ����.
	// �� �� long long���� ������ ��
	
	scanf("%lld %lld", &a, &b);
	sum = a + b;
	printf("%lld", sum);
	return 0;
}