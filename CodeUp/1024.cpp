#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char word[21] = "";
	scanf("%s", word);
	
	int i = 0;
	while (word[i] != NULL) {
		printf("'%c'\n", word[i]);
		i++;
	}
	return 0;
}