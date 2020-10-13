//求日期差，注意闰年是29号
//https://www.nowcoder.com/practice/ccb7383c76fc48d2bbc27a2a6319631c?tpId=62&tqId=29468&tPage=2&ru=/kaoyan/retest/2002&qru=/ta/sju-kaoyan/question-ranking
#include<cstdio>

int dayOfMonth[2][13] = {
    0,31,28,31,30,31,30,31,31,30,31,30,31,
    0,31,29,31,30,31,30,31,31,30,31,30,31
    };

int isLeapYear(int year){
    return year % 100 == 0 ? year % 400 == 0 : year % 4 == 0;
}

int countDaySinceBegin(int year, int month, int day){
    int days = 0;
    for(int i = 1; i < year; i++){
        if(isLeapYear(year)){
            days += 365;
        }else{
            days += 366;
        }   
    }
    for(int i = 0; i < month; i++){
        days += dayOfMonth[isLeapYear(year)][i];
    }
    days += day;
    return days;
}

int main(){
    int year1, month1, day1;
    int year2, month2, day2;
    char s1[9], s2[9];
    while(scanf("%s %s", s1, s2) != EOF){
        sscanf(s1, "%4d%2d%2d", &year1, &month1, &day1);
        sscanf(s2, "%4d%2d%2d", &year2, &month2, &day2);
        int days2 = countDaySinceBegin(year2, month2, day2);
        int days1 = countDaySinceBegin(year1, month1, day1);
        printf("%d\n",days2 - days1);
    }
    return 0;
}