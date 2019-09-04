#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    char numberOfForcesString[3], Line[40];
    int numberOfForces=0,data=4,i=0;
//    float *lines;
    float **rNF;
    float totalTorque=0;
    printf("Enter number of Forces:\n");
    gets(numberOfForcesString);
    numberOfForces = strtol(numberOfForcesString,NULL,10);
    rNF = (float **) (malloc( numberOfForces*sizeof(float *)));
    for (i=0; i<numberOfForces; i++){
        rNF[i]= (float *) (malloc(data* sizeof(float)));
    }
    for(i=0; i<numberOfForces; i++){
        printf("Enter Line #%d\n",i+1);
        gets(Line);
        rNF[i] = stringDividerToNumbers(Line,data);
//        for(j=0;j<data;j++){
//            rNF[i][j]=lines[j];
//        }
    }
    for(i=0; i<numberOfForces; i++){
        printf("\n%f\t%f\t%f\t%f\n",rNF[i][0],rNF[i][1],rNF[i][2],rNF[i][3]);
        totalTorque = totalTorque + (rNF[i][0] * rNF[i][3] - rNF[i][1] * rNF[i][2]);
    }
    printf("\nNet Torque : %.3f k", totalTorque);
    getch();
    return 0;
}
