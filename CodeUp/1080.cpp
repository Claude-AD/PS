#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, i = 0, sum = 0; // n은 입력받을 정수, i는 sum에 차례대로 더해갈 정수
	scanf("%d", &n);

	while (sum < n) {
		i++;
		sum += i;
	}
	printf("%d\n", i);
	return 0;
}