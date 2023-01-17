#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int idF, idB;
	scanf("%d-%d", &idF, &idB); // scanf 서식 지정할 때, 문자열은 %d-%d 처럼 입력 받는 것들 사이에
							// 문자를 넣어서 서식을 정해줄 수 없다. 어디까지가 문자열인지 모르기 때문
	printf("%06d%07d", idF, idB);
	return 0;
}