//sscanf的使用，年份从1开始
//https://www.nowcoder.com/practice/ccb7383c76fc48d2bbc27a2a6319631c?tpId=62&tqId=29468&tPage=2&ru=/kaoyan/retest/2002&qru=/ta/sju-kaoyan/question-ranking
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int days[][13]={
    0,31,28,31,30,31,30,31,31,30,31,30,31,
    0,31,29,31,30,31,30,31,31,30,31,30,31,
};

int isLeapYear(int year){
    return year % 100 ==0 ? year % 400 == 0 :year % 4 == 0;
}

int getDays(int year,int month,int day){
    int res = 0;
    for(int i = 0; i < year; i++){
        if(isLeapYear(i))
           res += 366;
        else
            res+= 365;
    }
    for(int i = 0; i < month; i++){
        if(isLeapYear(year)){
            res += days[1][i];
        }else{
            res += days[0][i];
        }
    }
    res += day;
    return res;
}


int main(){
    char s1[9],s2[9];
    while(cin>>s1>>s2){ 
        int year1, month1, day1;
        int year2, month2, day2;
        sscanf(s1,"%4d%2d%2d",&year1,&month1,&day1);
        sscanf(s2,"%4d%2d%2d",&year2,&month2,&day2);
        int ans = getDays(year2, month2, day2) - getDays(year1, month1, day1) + 1;
        printf("%d\n",ans);
    }
    return 0;
}