#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	long long a, r, n;
	scanf("%lld %lld %lld", &a, &r, &n);

	for (int i = 1; i < n; i++) {
		a *= r;
	}
	printf("%lld\n", a);
	return 0;
}