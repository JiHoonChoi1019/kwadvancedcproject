#ifndef __legd_list_h__
#define __legd_list_h__

#define LEGD_SIZE (sizeof(legd_list) - sizeof(legd_list*))

typedef struct __legd_list {
	char isalive;
	int money;
	char date[7];
	char store[20];
	int category;
	struct __legd_list * node;
} legd_list;

void push_legd(legd_list **head);
void income_legd(legd_list **head);
void show(legd_list *head);
void free_legd(legd_list *head);
int rectify(legd_list *head);
void list2file(legd_list *head, int i);

#endif // !__legd_list_h__
