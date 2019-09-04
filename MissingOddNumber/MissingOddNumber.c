#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

int power(int base, int operate){
    int powered=1;
    for (int i = 0; i < operate ; i++) {
        powered = powered*base;
    }
    return powered;
}

int stringToNumber(char* str){
    int i=0, len = strlen(str);
    int number=0;
    for (i=0; i<len; i++){
        number = number + ((str[len-i-1]-48)*((int) power(10,i)));
    }
    return number;
}

int* stringDividerToNumbers(char* str, int n){
    char number[4];
    int *start, *stop,j=0,i=0, *numbers;
    int flag=1;
    start = malloc(n* sizeof(int));
    stop = malloc(n* sizeof(int));
    numbers = malloc(n* sizeof(int));
    for(i=0; i<strlen(str); i++){
        if (flag==1 && str[i]!=32){
            start[j]=i;
            flag=0;
        }else if(str[i]==32 && flag==0){
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
        numbers[j] = stringToNumber(number);
//        printf("%s %d\n",number, numbers[j]);
    }
    return numbers;
}

int main() {
    int numbersCount = 0, sum = 0, sumAll = 0, i=0, missingNumber = 0;
    char numbers[100],n[5];
    int *oddNumbers;
    gets(n);
    numbersCount = strtol(n,NULL,10);
//    printf("\n%d\n",numbersCount);
//    scanf("%d" , &numbersCount );
//    oddNumbers = (int* ) malloc(numbersCount* sizeof(int));
    gets(numbers);
    oddNumbers = stringDividerToNumbers(numbers,numbersCount-1);
    for (i=0; i< numbersCount-1; i++){
//        printf("%d\n",oddNumbers[i]);
        sum += oddNumbers[i];
    }
    sumAll = numbersCount * numbersCount;
    missingNumber = sumAll - sum;
    printf("%d", missingNumber);
    getch();
    return 0;
}