#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int students[23] = {};
	int caseNum;
	unsigned char id;
	scanf("%d", &caseNum);

	for (int i = 0; i < caseNum; i++) {
		scanf("%hhu", &id);
		students[id - 1]++;
	}
	for (int i = 0; i < 23; i++) {
		printf("%d ", students[i]);
	}
	printf("\n");
	return 0;
}