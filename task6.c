//
// Created by victoria Sviridchik on 2020-03-13.
//

#include "myfile.h"
//Отцентрировать (т.е. обеспечить осевую симметрию текста на экране добавлением
//пробелов слева) вводимый с клавиатуры текст. Первый символ помещается в 40-ю
//позицию; второй – в 41-ю; появление третьего и каждого последующего нечетного
//символа вызывает удаление одного пробела слева. Так продолжается до конца строки;
//ввод следующих строк – аналогично.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define m 128

int from_str_to_int(const char s[125]) {
    if (s[0] == '-') {
        printf("%s", "Should be positive! EVERETHING\n");
        return -1;
    }
    int i = 0, sum = 0;
    while (s[i] != '\0') {
        if (s[i] <= '9' && s[i] >= '0' && sum < INT_MAX / 100) {
            sum = sum * 10 + (s[i] - '0');
            i++;
        } else {
            printf("%s", "Should be a NUMBER!\n");
            return -1;
        }
    }
    return sum;
}

int task2() {
    int i,n,j,k;
    char tmp[125];
    printf("Enter amount of strings: \n");
    scanf("%s",tmp);
    n = from_str_to_int(tmp);
    //scanf("%d",&n);
    char **stroki;
    stroki = (char **) malloc(n * sizeof(char*));
    for(i = 0; i < n; i++) {
        stroki[i] = (char *)malloc(m*sizeof(char));
    }
    //char stroki[n][m];
    int len[n];
    //fill numbers
    for (i = 0,j = 0; i < n; i++) {
        stroki[i][j] = (char)(i+'0');
        //printf("%c\n", stroki[i][j]);
    }
    for(i=-1;i<n;i++){
        j = 1;
        int count = 0;
        char s;
        scanf("%c",&s);
        while (s != '\n'){
            stroki[i][j] = s;
            scanf("%c",&s);
            j++;
            count = j;
        }
        len[i] = count;
    }


    //output
    for(i=0;i<n;i++){
        int start = 40 - (len[i]-1)/2;
        //printf("%d\n",start);
        for(; start>0; start--){
            printf(" ");
        }
        for(j=1;j<len[i];j++){
            printf("%c",stroki[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < n; i++) {
        free(stroki[i]);
    }
    free(stroki);
    return 0;
}