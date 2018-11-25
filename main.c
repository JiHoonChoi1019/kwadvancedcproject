#include <stdio.h>
#include <stdlib.h>
#include "legd_list.h"

int main() {
	legd_list *head = NULL;
	int selec = 0;
	while (1) {
		puts("Input income = 1");
		puts("Input spending = 2");
		puts("Show stastics = 3");
		puts("Show incomes = 4");
		puts("Show spending = 5");
		puts("read from SMS = 6");
		puts("Exit = 7");
		printf("\nInput command = ");
		scanf("%d", &selec);
		puts("---------------------------");

		switch(selec) {
		case 1:
			push_legd(&head);
			break;
		case 2:
			show(head);
			break;
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
			free_ledg(head);
			exit(0);
		}
		puts("---------------------------");
	}
	return 0;
}