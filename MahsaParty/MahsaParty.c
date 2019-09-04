#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>


int stringToNumber(char* str){
    int i=0, len = strlen(str);
    int number=0;
    for (i=0; i<len; i++){
        number = number + ((str[len-i-1]-48)*((int) pow(10,i)));
    }
    return number;
}

int main(){
    char asami[100],esm[50][20],n1[3],isUnique=0;
    int *start, *stop,j=0,i=0,n=0, *tedad, *uniques,**ids;
    int flag=1;
    gets(n1);
//    printf("%s\n",n1);
    n= stringToNumber(n1);
//    printf("%d\n",n);
    start = malloc(n* sizeof(int));
    stop = malloc(n* sizeof(int));
    tedad = malloc(n* sizeof(int));
    uniques = malloc(n* sizeof(int));
    ids = (int** )malloc(n* sizeof(int*));
    for(i=0;i<n;i++) {
        ids[i] = (int *) malloc((n - 1) * sizeof(int *));
        for (int k = 0; k < n-1; k++) {
            ids[i][k]=i;
        }
    }
//    esm = (char **) malloc(n* sizeof(char));
//    for (i=0; i<n; i++)
//        esm[i] = (char *)malloc(20 * sizeof(char));
    gets(asami);
    strcpy(asami,strlwr(asami));
//    printf("%s\n",asami);
    for(i=0; i<strlen(asami); i++){
//        printf("%d\n", i);
        if (flag==1){
            start[j]=i;
            flag=0;
        }else if(asami[i]==32){
            stop[j]=i-1;
            j++;
            flag=1;
        }
    }
    start[0]=0;
    stop[j]=strlen(asami)-1;
    for(j=0; j<n; j++){
//        printf("Start: %d \t Stop: %d\n",start[j],stop[j]);
        for( i = start[j]; i<=stop[j]; i++){
            esm[j][i-start[j]]=asami[i];
        }
        esm[j][i-start[j]]='\0';
        esm[j][0] = esm[j][0] - 32;
//        printf("%s\n",esm[j]);
        tedad[j]=1;
    }
    for(i=0; i<n; i++) {
        tedad[i]=0;
        uniques[i]=1;
    }
    int k=0;
    for(i=0; i<n; i++){
        k=0;
        tedad[i]++;
        for (j=0; j<n; j++){
            if (strcmp(esm[i],esm[j])==0 && i!=j){
                strcpy(esm[j],"");
                tedad[i]++;
                uniques[j]=0;
                ids[i][k]=j;
                k++;
            }
        }
    }
    for(i=0; i<n; i++) {
        if(uniques[i]) {
            printf("%s %d %d", esm[i],tedad[i],ids[i][tedad[i]-1]+1);
            for(j=1; j<tedad[i];j++){
                printf(",%d",ids[i][tedad[i]-1-j]+1);
            }
            printf("\n");
        }

    }
    getch();
    return 0;
}