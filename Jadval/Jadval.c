#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int stringToNumber(char* str){
    int i=0, len = strlen(str);
    int number=0;
    for (i = 0; i < len; i++) {
        number = number + ((str[len - i - 1] - 48) * ((int) pow(10, i)));
    }
    return number;
}

int * stringDividerToNumbers(char* str, int n){
    char number[4];
    int *start, *stop,j=0,i=0;
    int *numbers;
    int flag=1;
    start = malloc(n* sizeof(int));
    stop = malloc(n* sizeof(int));
    numbers = malloc(n* sizeof(float));
    for(i=0; i<strlen(str); i++){
        if (flag==1){
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
        numbers[j] = stringToNumber(number);
//        printf("%s %d\n",number, numbers[j]);
    }
    return numbers;
}

int main() {
    unsigned char n,m,s,flag=0;
    char line[11];
    int *nms;
    printf("m,n,s\n");
    gets(line);
    nms = stringDividerToNumbers(line,3);
    n=nms[0];
    m=nms[1];
    s=nms[2];
    for(char i=0; i<n;i++){
        for (char j = 0; j < s*m + m+1; j++) {
            printf("#");
        }
        printf("\n");
        for(char k=0; k<s; k++) {
            for (char j = 0; j < s*m + m+1; j++) {
                for (char z=0; z<=m; z++){
                    if (j==(s+1)*z){
                        flag=1;
                    }
                }
                if(flag==1){
                    printf("#");
                }else{
                    printf(" ");
                }
                flag=0;
            }
//            printf("#");
//            for (char z=0; z<s; z++){
//                printf(" ");
//           }
        printf("\n");
        }
    }
    for (char j = 0; j < s*m + m+1; j++) {
        printf("#");
    }
    getch();
    return 0;
}