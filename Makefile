main.out : main.o legd_list.o basic_func.o
	gcc main.o legd_list.o basic_func.o -o main.out
main.o : main.c legd_list.h basic_func.h
	gcc main.c -o main.o -c
legd_list.o : legd_list.c legd_list.h
	gcc legd_list.c -o legd_list.o -c
basic_func.o : basic_func.c basic_func.h
	gcc basic_func.c -o basic_func.o -c