#include <stdio.h>
#include <conio.h>

struct fard {
    char esmeFard[20], birthdayDate[10];
    int birthdayDay, birthdayMonth, birthdayYear;
};

struct fard dateChanger(char *date){
    struct fard dat;
    dat.birthdayDay = (date[0]-48)*10 + (date[1]-48);
    dat.birthdayMonth = (date[2]-48)*10 + (date[3]-48);
    dat.birthdayYear = (date[4]-48)*1000 + (date[5]-48)*100 + (date[6]-48)*10 + (date[7]-48);
    return dat;
}

int main() {
    struct fard friends[10],temp;
    char date[10];
    int friendsNum, day, month, year;
    printf("Tedad Doostan");
    scanf("%d",&friendsNum);
    for(int i=0; i<friendsNum; i++){
        printf("Esm %d\n", i+1);
        scanf("%s", friends[i].esmeFard);
        printf("Tarikh %d\n", i+1);
        scanf("%s", friends[i].birthdayDate);
        temp = dateChanger(friends[i].birthdayDate);
        friends[i].birthdayDay = temp.birthdayDay;
        friends[i].birthdayMonth = temp.birthdayMonth;
        friends[i].birthdayYear = temp.birthdayYear;
    }
    printf("Tarikhe Emrooz\n");
    scanf("%s", date);
    temp = dateChanger(date);
    day = temp.birthdayDay;
    month = temp.birthdayMonth;
    year = temp.birthdayYear;
    for (int i = 0; i <friendsNum ; i++) {
        if (friends[i].birthdayDay == day && friends[i].birthdayMonth == month){
            printf("Happy %dth Birthday %s!\n", year - friends[i].birthdayYear, friends[i].esmeFard);
        }
    }
    getch();
    return 0;
}
