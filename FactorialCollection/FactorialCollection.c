#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

unsigned long int factorial(int nF);

int main() {
    int i=1, *a;
    unsigned int n,sum=0;
    scanf("%d",&n);
    while(1){
        if(factorial(i)>n){
            break;
        }
        i++;
    }
    i--;
    a = (int*) malloc(i* sizeof(int));
    for (int j = 0; j <i  ; j++) {
        a[j]=0;
    }
    while(1){
        for (int j = i; j > 0 ; j--) {
            for (int k =j ; k>0  ; k--) {
                sum = sum + (k*factorial(j));
//                printf("%d\n",sum);
                if(sum > n){
                    sum = sum - k*factorial(j);
                    continue;
                }else {
                    a[j - 1] = k;
                    break;
                }

            }
            if(sum==n){
                break;
            }
        }
        if(sum==n){
            break;
        }
        break;
    }
//    printf("%d",sum);
    printf("\n%d =",n);
    for (int j = 0; j < i ; j++) {
        if(j==0){
            printf(" %d*%d! ",a[j],j+1);
        }else {
            printf("+ %d*%d! ", a[j], j + 1);
        }
    }
    getch();
    return 0;
}

unsigned long int factorial(int nF){
    if(nF==1){
        return 1;
    }
    return nF*factorial(nF-1);

}