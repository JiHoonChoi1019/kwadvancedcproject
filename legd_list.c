#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "legd_list.h"

void push_legd(legd_list **head) {
	system("cls");
	legd_list *newlegd = (legd_list *)malloc(sizeof(legd_list));
	printf("How much = ");
	scanf("%d", &newlegd->money);
	printf("Date (ex. 181116) = ");
	scanf("%d", &newlegd->date);
	printf("Where = ");
	scanf("%s", newlegd->store);
	printf("Categorize (Food = 1 / Transport = 2 / Pleasure = 3) = ");
	scanf("%d", &newlegd->category);

	newlegd->node = *head;
	*head = newlegd;

	char more;
	while (1) {
		printf("More to Input? (Y, N) : ");
		while (getchar() == NULL);	//clear input buffer

		more = getchar();

		if (more == 'y' || more == 'Y') {
			push_legd(head);
			break;
		}
		else if (more == 'n' || more == 'N') {
			do {
				show(*head);
			} while (rectify(*head));
			list2file(*head);
			break;
		}
		else
			printf("Please input Y or N.\n");
	}
	return;
}
void show(legd_list *cursor) {
	system("cls");
	int index = 1;
	while (cursor != NULL) {
		printf("Index = %d\n", index++);
		printf("Store = %s\n", cursor->store);
		printf("Money = %d\n", cursor->money);
		printf("Date = %d\n", cursor->date);
		switch(cursor->category) {
		case 1:
			printf("category = Food\n\n");
			break;
		case 2:
			printf("category = Transport\n\n");
			break;
		case 3:
			printf("category = Pleasure\n\n");
			break;
		}
		cursor = cursor->node;
	}
	return;
}
void free_ledg(legd_list *head) {
	legd_list *cursor;
	while (head != NULL) {
		cursor = head->node;
		free(head);
		head = cursor;
	}
	return;
}

int rectify(legd_list *head) {
	int index;
	printf("Anything recity?\n");
	printf("Input index to rectify (Input 0 if anything okay) = ");
	scanf("%d", &index);
	if (index == 0)
		return 1;

	system("cls");

	for (int i = 1; i == index; i++)
		head = head->node;

	printf("How much = ");
	scanf("%d", head->money);
	printf("Date (ex. 181116) = ");
	scanf("%d", head->date);
	printf("Where = ");
	scanf("%s", head->store);
	printf("Categorize (Food = 1 / Transport = 2 / Pleasure = 3) = ");
	scanf("%d", head->category);

	return 0;
}

void list2file(legd_list * head) {
	
}
