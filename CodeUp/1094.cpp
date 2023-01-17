#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int caseNum;
	scanf("%d", &caseNum);

	int* students = new int[caseNum];
	for (int i = 0; i < caseNum; i++) {
		scanf("%d", &students[i]);
	}
	for (int i = caseNum - 1; i >= 0; i--) {
		printf("%d ", students[i]);
	}
	printf("\n");

	delete[] students;
	return 0;
}