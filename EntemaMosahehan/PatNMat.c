#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

float * stringDividerToNumbers(char* str, int n){
    char number[8];
    int *start, *stop,j=0,i=0;
    float *numbers;
    int flag=1;
    start = malloc(n* sizeof(int));
    stop = malloc(n* sizeof(int));
    numbers = malloc(n* sizeof(float));
    for(i=0; i<strlen(str); i++){
        if (flag==1){
            if(str[i]==32) continue;
            start[j]=i;
            flag=0;
        }else if(str[i]==32){
            stop[j]=i-1;
            j++;
            flag=1;
        }
    }
    start[0]=0;
    stop[j]=strlen(str)-1;
    for(j=0; j<n; j++){
        for( i = start[j]; i<=stop[j]; i++){
            number[i-start[j]]=str[i];
        }
        number[i-start[j]]='\0';
        numbers[j] = strtof(number,NULL);
//        printf("%s %d\n",number, numbers[j]);
    }
    return numbers;
}



int main() {
    int patsNum = 0, matsNum = 0, totalBarge = 0, i = 0, j = 0,*number;
    char patsGrades[100],matsGrades[100],num[10],*ptr;
    float * nomreha,tempNumber = 0;
    gets(num);
    patsNum = strtol(num,&ptr,10);
    matsNum = strtol(ptr,NULL,10);
    totalBarge = patsNum + matsNum;
    gets(patsGrades);
    gets(matsGrades);
    nomreha = (float*) malloc(totalBarge* sizeof(float));
    strcat(patsGrades," ");
    strcat(patsGrades,matsGrades);
//    printf("%s",patsGrades);
    nomreha = stringDividerToNumbers(patsGrades, patsNum+matsNum);

    for (i = 0; i < totalBarge; ++i){
//        printf("%f",nomreha[i]);
        for (j = i + 1; j < totalBarge; ++j) {
            if (nomreha[i] > nomreha[j]) {
                tempNumber = nomreha[i];
                nomreha[i] = nomreha[j];
                nomreha[j] = tempNumber;
            }
        }
    }
    for(i=0; i<totalBarge; i++){
        printf("%4.2f \t", nomreha[i]);
    }
    getch();
    return 0;
}