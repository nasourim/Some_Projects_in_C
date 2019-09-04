#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

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
    char LW[12], Line[40];
    int L,W,i=0,j=0,*lines,maxHeight[3]={0,0,0};
    printf("Enter L and W:\n");
    gets(LW);
    int *LWint = stringDividerToNumbers(LW,2);
    L=LWint[0];
    W=LWint[1];
//    printf("L: %d , W: %d\n", L,W);
    int **height = (int**) (malloc( L*sizeof(int*)));
    for (i=0; i<L; i++){
        height[i]= (int*) (malloc(W* sizeof(int)));
    }
    for(i=0; i<L; i++){
        printf("Enter Line #%d\n",i+1);
        gets(Line);
        lines = stringDividerToNumbers(Line,W);
        for(j=0;j<W;j++){
            height[i][j]=lines[j];
        }
    }
    for(i=0; i<L; i++){
        for(j=0;j<W;j++){
            if (height[i][j]>maxHeight[0]){
                maxHeight[0] = height[i][j];
                maxHeight[1] = i;
                maxHeight[2] = j;
            }
        }
    }
    printf("(%d,%d) : %d", maxHeight[1]+1, maxHeight[2]+1, maxHeight[0]);
    getch();
    return 0;
}
