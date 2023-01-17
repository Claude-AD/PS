#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int n, m;
	scanf("%d", &n);
reload:
	scanf("%d", &m);
	printf("%d\n", m);
	if (--n != 0) goto reload;
	else return 0;
}