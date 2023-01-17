#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	double w, h, b;
	scanf("%lf %lf %lf", &w, &h, &b);

	int convBitToMB = 8 * 1024 * 1024;
	printf("%.2lf MB\n", w * h * b / convBitToMB);
	return 0;
}