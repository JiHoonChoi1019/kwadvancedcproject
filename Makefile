main.out : main.o legd_list.o
	gcc main.o legd_list.o -o main.out
main.o : main.c legd_list.h
	gcc main.c -o main.o -c
legd_list.o : legd_list.c legd_list.h
	gcc legd_list.c -o legd_list.o -c