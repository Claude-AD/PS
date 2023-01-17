#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	long long a, b, sum; 
	// a와 b가 int의 범위를 넘지 않는다고 해서 int로 선언해버리면
	// long long 값인 sum으로 들어가기 전에 이미 오버플로우 되어버리므로 의미가 없다.
	// 꼭 다 long long으로 선언할 것
	
	scanf("%lld %lld", &a, &b);
	sum = a + b;
	printf("%lld", sum);
	return 0;
}