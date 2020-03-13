//
// Created by victoria Sviridchik on 2020-03-13.
//

#include "myfile.h"
//Текстовый файл содержит текст произвольной длины. Построить вертикальную
//гистограмму числа вхождений в текст каждой строчной латинской буквы.


#include <stdio.h>
#include <stdlib.h>

#define n 26
//int int_to_char(){
//
//}
int count_times(const char a[], char letter) {
    int j = 0, answer = 0;
    while (a[j] != '\0') {
        if (a[j] == letter) {
            answer++;
        }
        j++;
    }
    return answer;
}


int task1() {
    FILE *fp;
    FILE *fp1;
    int i = 0;
    int count[26];
    fp = fopen("data1.txt", "r+");
    //fp1 = fopen("result.txt", "r+");
    if (fp == NULL) {
        printf("It looks like there are some problems \n");
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);

    fseek(fp, 0, SEEK_SET);
    char *data;
    data = (char *) malloc(size * sizeof(char));
    //char data[size];
    while (!feof(fp)) {
        char s;
        int k = fscanf(fp, "%c", &s);
        if (s == '\n' || s == '\0' || s == ' ' || k == -1) {
            continue;
        } else {

            data[i] = s;
            i++;
        }
    }
    data[i] = '\0';
    int j = 0;

    char c;
    int ii = 0, max = -1;
    for (c = 'a'; c <= 'z'; c++) {

        int b = count_times(data, c);
        if (b > max) {
            max = b;
        }
        count[(int) c - 'a'] = b;
        //printf("%d\n",b);
    }

    char graphic[max][27];
    for (j = 0; j < 27; j++) {
        for (i = 0; i < max + 1; i++) {
            graphic[i][j] = '0';
        }
    }
    graphic[0][0]=' ';


//    int m = max;
//    printf("%c\n", (char) (0 + '0'));
//    for (i = 1, j = 0; i < max + 1; i++) {
//        graphic[i][j] = (char) (m + '0');
//        //printf("%c\n",(char)(m+'0'));
//        m--;
//    }
    //int m = max;
    //printf("%c\n", (char) (0 + '0'));
    for (i = 1, j = 0; i < max + 1; i++) {
        graphic[i][j] = ' ';
        //printf("%c\n",(char)(m+'0'));
    }

    for (i = 1, j = 0; i < 27; i++) {
        graphic[j][i] = (char) (i - 1 + (int) 'a');
        //printf("%c\n",graphic[i][j]);
    }

    while (1) {
        for (j = 1; j <= 26; j++) {
            int buf = count[j - 1];
            for (i = max; i > 0; i--) {

                if (buf > 0) {
                    graphic[i][j] = '*';
                    buf--;
                } else {
                    graphic[i][j] = ' ';
                }
            }
        }
        break;
    }


    for (i = 0; i < max + 1; i++) {
        int t = max+1-i;
        if (i==0) printf ("     ");
        else
        if (t<=9) printf ("%c    ",t+'0');
        else
        if (t<=99) printf ("%c%c   ",t/10+'0',t%10+'0');
        else
        if (t<=999) printf ("%c%c%c  ",t/100+'0',t/10%10+'0',t%10+'0');
        else
            printf ("%c%c%c%c ",t/1000+'0',t/100%10+'0',t/10%10+'0',t%10+'0');


        for (j = 0; j < 27; j++) {

            printf("%c\t", graphic[i][j]);
        }
        printf("\n");
    }


    fclose(fp1);
    fclose(fp);
    free(data);
    return 0;
}