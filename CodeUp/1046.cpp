#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int a, b, c;
	long long sum = 0;
	scanf("%d %d %d", &a, &b, &c);

	sum = a + b + c;
	printf("%lld\n", sum);
	printf("%.1lf\n", (double)sum / 3);
	return 0;
}