#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "legd_list.h"
#include "basic_func.h"

int main() {
	legd_list *head = NULL;
	int selec = 0;
	while (1) {
		selec = showFunc();

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
		system("clear");
	}
	return 0;
}