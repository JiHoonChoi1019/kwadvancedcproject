#include <stdio.h>
#include <stdlib.h>
#include "legd_list.h"

int main() {
	int selec = 0;
	while (1) {
		puts("Input income = 1");
		puts("Input spending = 2");
		puts("Show stastics = 3");
		puts("Show incomes = 4");
		puts("Show spending = 5");
		puts("read from SMS = 6");
		puts("Exit = 7");
		scanf("%d", &selec);

		legd_list *head;
		legd_list *cursor = head;

		switch(selec) {
		case 1:
			push_legd(cursor);
			break;
		case 2:
			show(head);
			break;
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			exit(0);
		}
	}
	return 0;
}