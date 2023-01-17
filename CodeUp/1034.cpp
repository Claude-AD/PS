#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	// C언어에서 소스 코드 작성 시 0으로 시작하는 수는 8진수로 인식된다. 
	// int a = 013; -> 10진수 11과 같은 값
	int n;
	scanf("%o", &n);
	printf("%d", n);
	return 0;
}