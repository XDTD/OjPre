//Day of week,z注意检测闰年的时候是i不是year
//https://www.nowcoder.com/practice/a3417270d1c0421587a60b93cdacbca0?tpId=62&tqId=29465&tPage=1&ru=/kaoyan/retest/2002&qru=/ta/sju-kaoyan/question-ranking

#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int daysOfMonth[2][13] = {
    0,31,28,31,30,31,30,31,31,30,31,30,31,
    0,31,29,31,30,31,30,31,31,30,31,30,31,
};

string nameOfMonths[13] = {
    "","January", "February", "March", "April", "May", "June", 
    "July", "August", "September", "October", "November", "December"
};

string nameOfDays[7] ={
     "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
};

int isLeapYear(int year){
    return year % 100 == 0 ? year % 400 == 0 : year % 4 == 0;
}


int getIdx(string name, string nameOfMonths[]){
    int ans = 0;
    for(int i = 0; i < 13; i++){
        if(name == nameOfMonths[i])
            ans = i;
    }
    return ans;
}

int countDaysSinceBegin(int year, int month, int day){
    int days = 0;
    for(int i = 1; i < year; i++){
        if(isLeapYear(i))    //这里是i不是year
            days += 366;
        else
            days += 365;
    }
    for(int i = 0; i < month; i++){
        days += daysOfMonth[isLeapYear(year)][i];
    }
    days += day;
    return days;
}

int main(){
    int year, month, day;
    string s;
    while(cin >>day >>s >>year ){
        month = getIdx(s, nameOfMonths);
        int  days = countDaysSinceBegin(year, month, day);
        days =(days - 1) % 7;
        cout << nameOfDays[days] << endl;
    }
    return 0;
}