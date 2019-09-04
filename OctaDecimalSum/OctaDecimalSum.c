#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

unsigned long long int power(char n);

unsigned  long long int octaStringToInt (char* number);

char * intToOctadecimeal(unsigned long long int number);

int main() {
    char number1[500],number2[500];
    gets(number1);
    gets(number2);

    printf("\n\n%s", intToOctadecimeal(octaStringToInt(number1) + octaStringToInt(number2)));
    getch();
    return 0;
}


unsigned long long int power(char n){
    unsigned long long int powered=1;
    for (char i = 0; i < n ; ++i) {
        powered = powered * 18;
    }
    return powered;
}

unsigned long long int octaStringToInt (char* number){
    unsigned long long int numb=0;
    for (unsigned char i=0; i<strlen(number); i++){
        if(number[strlen(number)-1-i]>=65 && number[strlen(number)-1-i]<=72){
            numb = numb + ((number[strlen(number)-1-i] - 55) * power(i));
//            printf("\n%c\t%d",(number[strlen(number)-1-i]),(number[strlen(number)-1-i] - 55));
        }else if(number[strlen(number)-1-i]>=97 && number[strlen(number)-1-i]<=104){
            numb = numb + ((number[strlen(number)-1-i] - 87) * power(i));
//            printf("\n%c\t%d",(number[strlen(number)-1-i]),(number[strlen(number)-1-i] - 87));
        } else {
            numb = numb + ((number[strlen(number)-1-i] - 48) * power(i));
        }
    }
//    printf("\n*%llu\n",numb);
    return numb;
}

char * intToOctadecimeal(unsigned long long int number){
    char buffer[37];
    char *pConvertedNumber,*returnedNum;
    char allValues[] = "0123456789ABCDEFGH";

    pConvertedNumber = &buffer[sizeof(buffer)-1];

    *pConvertedNumber = '\0';

    do {

        int value = number % 18;
        pConvertedNumber = pConvertedNumber - 1;

        *pConvertedNumber = allValues[value];

        number /= 18;

    } while(number != 0);
    returnedNum = (char*) malloc(strlen(pConvertedNumber)* sizeof(char));
    char i=0;
    for(i=0; i<strlen(pConvertedNumber); i++){
        returnedNum[i] = pConvertedNumber[i];
    }
    returnedNum[i]='\0';
    return returnedNum;
}