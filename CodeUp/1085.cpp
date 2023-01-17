#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	double h, b, c, s;
	scanf("%lf %lf %lf %lf", &h, &b, &c, &s);

	int convBitToMB = 8 * 1024 * 1024;
	printf("%.1lf MB\n", h * b * c * s / convBitToMB);
	return 0;
}