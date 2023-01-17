#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	unsigned int a;
	int b;
	scanf("%u %d", &a, &b);

	printf("%lld\n", (long long)a + b);
	printf("%d\n", a - b);
	printf("%d\n", a * b);
	printf("%d\n", a / b);
	printf("%d\n", a % b);
	printf("%.2lf\n", (double)a / b);
}