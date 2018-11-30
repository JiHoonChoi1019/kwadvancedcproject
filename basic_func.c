#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "basic_func.h"

int showFunc() {
	int selec;
	puts("Input income = 1");
	puts("Input spending = 2");
	puts("Show stastics = 3");
	puts("Show incomes = 4");
	puts("Show spending = 5");
	puts("read from SMS = 6");
	puts("Exit = 7\n");
	printf("Input command = ");
	scanf("%d", &selec);
	return selec;
}
