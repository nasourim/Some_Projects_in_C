#include <stdio.h>
#include <math.h>
#include <conio.h>

double power(double base, int operate){
    double powered=1;
    for (int i = 0; i < operate ; i++) {
        powered = powered*base;
    }
    return powered;
}

int main() {
    double x;
    double taylor=0,taylor2=0;
    int n;
    scanf("%d %lf",&n,&x);
//    printf("%d %lf\n",n,x);
    for(int i=1; i<n+1; i++){
        taylor = taylor + (power(-1,i+1)*power(x,i)/i);
//        printf("%lf\n",taylor);
    }
    for(int i=1; i<2*n+1; i++){
        taylor2 = taylor2 + (power(-1,i+1)*power(x,i)/i);
//        printf("%lf\n",taylor2);
    }
    printf("%lf %lf",taylor, fabs(taylor-taylor2));
    getch();
    return 0;
}