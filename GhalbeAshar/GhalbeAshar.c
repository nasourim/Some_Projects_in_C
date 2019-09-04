#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int stringToNumber(char* str){
    int i=0, len = strlen(str),pow=1;
    int number=0;
    for (i=0; i<len; i++){
        for (int j = 0; j <i ; ++j) {
            pow = pow*10;
        }
        number = number + ((str[len-i-1]-48)* pow);
        pow=1;
    }
    return number;
}

int* stringDividerToNumbers(char* str, int n){
    char number[20],revNumber[20];
    int *start, *stop,j=0,i=0, *numbers;
    int flag=1;
    start = malloc(n* sizeof(int));
    stop = malloc(n* sizeof(int));
    numbers = malloc(3*n* sizeof(int));
    for(i=0; i<strlen(str); i++){
        if (flag==1){
            start[j]=i;
            flag=0;
        }else if(str[i]==46){
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
        for (int k=0; k<strlen(number); k++){
            revNumber[k]=number[strlen(number)-k-1];
        }
        revNumber[strlen(number)]='\0';
        numbers[j] = stringToNumber(number);
        numbers[n+j] = stringToNumber(revNumber);
        numbers[2*n+j] = strlen(number);
//        printf("%s %d\n",number, numbers[j]);
    }
    return numbers;
}

int main() {
    char line[20],revline[20];
    int *num;
    double revF;
    gets(line);
    for(int i=0;i<strlen(line);i++){
//        if(line[strlen(line)-1]==0){
//            revline[i]=line[strlen(line)-i-2];
//        }
        revline[i]=line[strlen(line)-i-1];
    }
        revline[strlen(line)] = '\0';
    revF = strtold(revline,NULL);
    num = stringDividerToNumbers(line,2);
//    revF = ((double) num[3]) + ((double) num[2] / num[4]);
    printf("%d\n%d\n%f\n",num[5],num[1],revF);
    getch();
    return 0;
}