#include <stdio.h>
#include <stdlib.h>
#include "legd_list.h"

void push_legd(legd_list *list) {
	legd_list *newlegd = (legd_list *)malloc(sizeof(legd_list));
	printf("How much = ");
	scanf("%d", &newlegd->money);
	printf("Date (ex. 181116) = ");
	scanf("%d", &newlegd->date);
	printf("Where = ");
	scanf("%s", newlegd->store);
	printf("Categorize (Food = 1 / Transport = 2 / Pleasure = 3) = ");
	scanf("%d", &newlegd->category);

	list = newlegd;

	newlegd->node = NULL;
	return;
}
void show(legd_list *head) {
	while (head != NULL) {
		printf("%s\n", head->store);
		printf("%d\n", head->money);
		printf("%d\n", head->date);
		head = head->node;
	}
	return;
}