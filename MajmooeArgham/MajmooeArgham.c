#include <stdio.h>
#include <conio.h>


unsigned int jamKon (unsigned int num){
    unsigned int sum=0;
    char flag=1;
    while(flag==1){
        sum += num % 10;
//        printf("%d",sum);
        if(num >9 ){
            num = num / 10;
        }else{
            flag=0;
        }
    }
    if(sum > 9 ){
        return jamKon(sum);
    }
    return sum;
}

int main() {
    unsigned int number,javab;
    scanf("%d",&number);
    javab = jamKon(number);
    printf("%d",javab);
    getch();
    return 0;
}