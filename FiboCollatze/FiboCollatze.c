#include <stdio.h>
#include <conio.h>


int collaSeries[100],c=0;
int fibonacci(int n)
{
    if (n == 0 || n == 1)
        return n;
    else
        return (fibonacci(n-1) + fibonacci(n-2));
}
/*
int collatz(int n){
    c++;
    if(n==1){
        collaSeries[c-1]=n;
        return n;
    } else {
        if(n%2==1){
            collaSeries[c-1]=3*n-1;
            return collatz(3*n-1);
        }else{
            collaSeries[c-1]=n/2;
            return collatz(n/2);
        }
    }
}*/
static int collatz(int n){
    collaSeries[c]=n;
    c++;
    if (n == 1) return 0;
    else if (n % 2 == 0) return 1 + collatz(n/2);
    else return 1 + collatz(3*n + 1);
}

int main() {
    unsigned int n;
    scanf("%d",&n);
//    printf("%d\n",n);
    int col = collatz(n);
//    printf("\n%d\n%d\n\n",c,col);
    for (int i = c; i > 0 ; i--) {
        printf("f(%d) = %d\n",collaSeries[i-1],fibonacci(collaSeries[i-1]));
    }
    getch();
    return 0;
}