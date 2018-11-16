#ifndef __legd_list_h__
#define __legd_list_h__

typedef struct __legd_list {
	int money;
	int date;
	char store[20];
	int category;
	struct legd_list * node;
} legd_list;

void push_legd(legd_list *list);
void show(legd_list *head);

#endif // !__legd_list_h__
