#include "file.h"
#include "legd_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void show_stastics() {
    system("clear");
    printf("Input year-month for view stastics (ex. 1811");
    char cdate[40] = "./legd_data/income/";
    char date[5];
    scanf("%s", date);
    strcat(cdate, date);

    int n1 = 0;
    int n2 = 0;
    int n3 = 0;
    
    legd_list *buf = (legd_list *)malloc(LEGD_SIZE);
    int fd = 0;
    if (fd = open(cdate, O_RDONLY, 0644) == -1)
        printf("There is no income data for the date you entered.\n");
    else {
        while (read(fd, buf, LEGD_SIZE) != 0) {
            switch(buf->category) {
            case 1:
                n1 += buf->money;
                break;
            case 2:
                n2 += buf->money;
                break;
            case 3:
                n3 += buf->money;
                break;
            }
        }
        close(fd);
    }
    printf("%s income : \n", date);
    printf("\t Pay\t= %d\n", n1);
    printf("\t Finance\t= %d\n", n2);
    printf("\t Others\t= %d\n", n3);

    strcpy(cdate, "./legd_data/expense/");
    strcat(cdate, date);
    n1 = 0; n2 = 0; n3 = 0;

    if (fd = open(cdate, O_RDONLY, 0644) == -1)
        printf("There is no expense data for the date you entered.\n");
    else {
        while (read(fd, buf, LEGD_SIZE) != 0) {
            switch(buf->category) {
            case 1:
                n1 += buf->money;
                break;
            case 2:
                n2 += buf->money;
                break;
            case 3:
                n3 += buf->money;
                break;
            }
        }
        close(fd);
    }
    printf("%s expense : \n", date);
    printf("\t Food\t= %d\n", n1);
    printf("\t Transport\t= %d\n", n2);
    printf("\t Pleasure\t= %d\n", n3);

    printf("--------------------------\n");
    printf("Press any key");
    getc(stdin);
}