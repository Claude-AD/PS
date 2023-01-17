#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	long long a, m, d, n;
	scanf("%lld %lld %lld %lld", &a, &m, &d, &n);

	for (int i = 1; i < n; i++) {
		a *= m;
		a += d;
	}
	printf("%lld\n", a);
	return 0;
}