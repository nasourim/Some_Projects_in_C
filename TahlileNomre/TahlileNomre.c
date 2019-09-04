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
    start[0]=1;
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
    char num[10],**ptr,**lines;
    float ** nomreha,avgAvg,avgMin,avgMax,*avg,*min,*max,tempNumber=0,temp1=0,temp2=0,n1=0,n2=0;
    int n=0,*m,j=0;
    gets(num);
    n = strtol(num,NULL,10);
//    printf("%d",n);
    lines = (char**) malloc(n* sizeof(char*));
    ptr = (char**) malloc(n* sizeof(char*));
    nomreha = (float **) malloc(n* sizeof(float *));
    m = (int*) malloc(n* sizeof(int));
    min = (float *) malloc(n* sizeof(float));
    max = (float *) malloc(n* sizeof(float));
    avg = (float *) malloc(n* sizeof(float));
    for (int i = 0; i < n ; i++) {
        lines[i] = (char*) malloc(100* sizeof(char));
        ptr[i] = (char*) malloc(100* sizeof(char));
        gets(lines[i]);
//        printf("%s\n",lines[i]);
        m[i] = strtol(lines[i],&ptr[i],10);
//        printf("%s\n",ptr[i]);
//        printf("%d\n",m[i]);
    }
    for (int i = 0; i < n ; i++) {
        nomreha[i] = (float *) malloc(n* sizeof(float));
        nomreha[i] = stringDividerToNumbers(ptr[i],m[i]);
    }

//    for (int i = 0; i < n ; i++) {
//        for (int k = 0; k < m[i] ; k++) {
//            printf("%d %f\n",i,nomreha[i][k]);
//        }
//    }


    for (int i = 0; i < n ; i++) {
        min[i]=20;
        max[i]=0;
        for (int k = 0; k < m[i] ; k++) {
            tempNumber = tempNumber + nomreha[i][k];
            if (max[i] < nomreha[i][k]) {
                max[i] = nomreha[i][k];
            }
            if (min[i] > nomreha[i][k]) {
                min[i] = nomreha[i][k];
            }
        }
        avg[i]=tempNumber/m[i];
        tempNumber=0;
//        printf("\n%f %f %f\n",avg[i],min[i],max[i]);
    }
    for(j=0; j<n; j++){
        temp1 = temp1 + min[j];
        tempNumber = tempNumber + avg[j];
        temp2 = temp2 + max[j];
    }
    avgMin = temp1 / n;
    avgAvg = tempNumber / n;
    avgMax = temp2 / n;

    printf("%f %f %f",avgAvg,avgMin,avgMax);
    getch();
    return 0;
}