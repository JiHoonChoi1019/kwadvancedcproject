#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "legd_list.h"

#define LEGD_SIZE (sizeof(legd_list) - sizeof(legd_list*))

void push_legd(legd_list **head) {
	system("clear");
	legd_list *newlegd = (legd_list *)malloc(sizeof(legd_list));
	printf("How much = ");
	scanf("%d", &newlegd->money);
	printf("Date (ex. 181116) = ");
	scanf("%s", newlegd->date);
	printf("Where = ");
	scanf("%s", newlegd->store);
	printf("Categorize (Food = 1 / Transport = 2 / Pleasure = 3) = ");
	scanf("%d", &newlegd->category);
	newlegd->isalive = 1;

	newlegd->node = *head;
	*head = newlegd;

	char more;
	while (1) {
		printf("More to Input? (Y, N) : ");
		while (getchar() == '\0');			//clear buffer
		more = getchar();

		if (more == 'y' || more == 'Y') {
			push_legd(head);
			break;
		}
		else if (more == 'n' || more == 'N') {
			do {
				show(*head);
			} while (rectify(*head) == 1);
			list2file(*head);
			break;
		}
		else
			printf("Please input Y or N.\n");
	}
	list2file(*head);
	return;
}
void show(legd_list *cursor) {
	system("clear");
	int index = 1;
	while (cursor != NULL) {
		printf("Index = %d\n", index++);
		printf("Store = %s\n", cursor->store);
		printf("Money = %d\n", cursor->money);
		printf("Date = %s\n", cursor->date);
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
		return 0;

	system("clear");

	for (int i = 1; i == index; i++)
		head = head->node;

	printf("How much = ");
	scanf("%d", &head->money);
	printf("Date (ex. 181116) = ");
	scanf("%s", head->date);
	printf("Where = ");
	scanf("%s", head->store);
	printf("Categorize (Food = 1 / Transport = 2 / Pleasure = 3) = ");
	scanf("%d", &head->category);

	return 1;
}

void list2file(legd_list * head) {
	if (mkdir("./legd_data/income", 0755) == -1) {
		perror("mkdir() error!");
		exit(-1);
	}
	printf("-----------------\n");
	sleep(3);

	while (head != NULL) {
		char date[6] = { 0, };
		strncpy(date, head->date, 5);
		char cdate[35] = "./legd_data/income/";
		strcat(cdate, date);
		mkdir(cdate, 0755);

		strcat(cdate, head->date);

		int fd = open(cdate, O_RDWR | O_CREAT);
		legd_list *buf = (legd_list *)malloc(LEGD_SIZE);
		memset(buf, '\0', LEGD_SIZE);

		while (1) {
			if (read(fd, (legd_list *)buf, LEGD_SIZE) == 0) {
				memcpy(buf, head, LEGD_SIZE);
				write(fd, (legd_list *)buf, LEGD_SIZE);
				free(buf);
				break;
			}
			else if (buf->isalive == 0) {
				lseek(fd, SEEK_CUR, -(LEGD_SIZE));
				memcpy(buf, head, LEGD_SIZE);
				write(fd, (legd_list *)buf, LEGD_SIZE);
				free(buf);
				break;
			}
		}
		head = head->node;
	}
	return;
}
