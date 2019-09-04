#include <stdio.h>
#include <string.h>
#include <conio.h>

void swap(char* left, char* right);

int main() {
    static char left[5], right[5],input[5];
    int n;
    scanf("%s",input);
    scanf("%d",&n);
    strcpy( input,strlwr(input));
    if(input[0]=='l'){
        strcpy(left,"gol");
        strcpy(right,"pooch");
    }else{
        strcpy(right,"gol");
        strcpy(left,"pooch");
    }
    for (int i = 0; i < n ; i++) {
        swap(left,right);
    }
    if(strcmp(left,"gol")==0){
        printf("Left");
    }else{
        printf("Right");
    }
    getch();
    return 0;
}

void swap(char* left, char* right){
    if(strcmp(left,"gol")==0){
        strcpy(right,"gol");
        strcpy(left,"pooch");
    }else{
        strcpy(left,"gol");
        strcpy(right,"pooch");
    }
}