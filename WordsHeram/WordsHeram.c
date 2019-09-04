#include <stdio.h>
#include <conio.h>

int main() {
    unsigned char n=0, radif=0,j,ch;
    scanf("%d",&n);
    for(radif=0; radif<n; radif++){
        ch=64;
        for(j=0; j<n-radif-1; j++){
            printf("   ");
        }
        while(j<(2*n-1)-(n-radif-1)){
            if(j<n){
//                printf("%d",j);
                ch++;
            }
            if(j>=n){
//                printf("%d",j);
                ch--;
            }
            printf(" %c ", ch);
            j++;
        }
        printf("\n");
    }
    getch();
    return 0;
}