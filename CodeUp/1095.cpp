#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	int caseNum;
	scanf("%d", &caseNum);

	int* students = new int[caseNum];
	for (int i = 0; i < caseNum; i++) {
		scanf("%d", &students[i]);
	}

	unsigned char min = students[0];
	for (int i = 1; i < caseNum; i++) {
		if (students[i] < min) min = students[i];
	}
	printf("%d\n", min);
	
	delete[] students;
	return 0;
}