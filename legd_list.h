#ifndef __legd_list_h__
#define __legd_list_h__

typedef struct __legd_list {
	int money;
	int date;
	char store[20];
	int category;
	struct __legd_list * node;
} legd_list;

void push_legd(legd_list **head);
void show(legd_list *head);
void free_ledg(legd_list *head);
int rectify(legd_list *head);
void list2file(legd_list *head);

#endif // !__legd_list_h__
