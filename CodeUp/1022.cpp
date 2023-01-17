#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char buf[2001];
	fgets(buf, 2000, stdin);
	printf("%s", buf);
	
	return 0;
}