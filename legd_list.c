#include <stdio.h>
#include <stdlib.h>
#include "legd_list.h"

void push_legd(legd_list **head) {
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

	return;
}
void show(legd_list *cursor) {
	while (cursor != NULL) {
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