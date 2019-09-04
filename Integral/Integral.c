#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

float * stringDividerToNumbers(char* str, int n){
    char number[4];
    int *start, *stop,j=0,i=0;
    float *numbers;
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
        numbers[j] = strtof(number,NULL);
//        printf("%s %d\n",number, numbers[j]);
    }
    return numbers;
}


int main() {
    char line[15];
    int s;
    float *nabs,*xi,*fxi,rieman=0,integralVal;
    gets(line);
    nabs = stringDividerToNumbers(line,4);
    s=(int) nabs[3];
    xi = (float*) malloc( (s+1) * sizeof(float));
    fxi = (float*) malloc( (s+1) * sizeof(float));
    for(int i=0; i<s+1; i++){
        xi[i] = nabs[1] + ((nabs[2]-nabs[1])/s)*i;
        fxi[i] = powf(xi[i],nabs[0]);
    }
    for (int i = 0; i <s ; i++) {
        rieman = rieman + (fxi[i]+fxi[i+1])*(xi[i+1]-xi[i])/2;
    }
    integralVal = (powf(nabs[2],nabs[0]+1)/(nabs[0]+1)) - (powf(nabs[1],nabs[0]+1)/(nabs[0]+1));
    printf("%.6f %.6f %.6f", integralVal, rieman, fabsf(integralVal-rieman));
    getch();
    return 0;
}