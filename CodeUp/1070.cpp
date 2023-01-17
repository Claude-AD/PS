#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	unsigned char n;
	scanf("%hhu", &n);

	switch (n) {
	case 12:
	case 1:
	case 2:
		printf("winter\n");
		break;

	case 3:
	case 4:
	case 5:
		printf("spring\n");
		break;

	case 6:
	case 7:
	case 8:
		printf("summer\n");
		break;

	case 9:
	case 10:
	case 11:
		printf("fall\n");
		break;

	default:
		printf("Wrong Input!!!\n");
		break;
	}
	return 0;
}