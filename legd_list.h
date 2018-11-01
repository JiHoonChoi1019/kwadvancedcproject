#ifndef __legd_list_h__
#define __legd_list_h__

struct legd_list {
	int money;
	int date;
	char store[20];
	struct legd_list * node;
};

void push_legd(struct legd_list list);


#endif // !__legd_list_h__
