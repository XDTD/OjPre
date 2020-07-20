//日期
//https://www.nowcoder.com/practice/a3417270d1c0421587a60b93cdacbca0?tpId=62&tqId=29465&tPage=1&ru=/kaoyan/retest/2002&qru=/ta/sju-kaoyan/question-ranking
#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int days[][13]={
    0,31,28,31,30,31,30,31,31,30,31,30,31,
    0,31,29,31,30,31,30,31,31,30,31,30,31
};

string months[13] = {
    "January", "February", "March", "April", "May", "June", 
    "July", "August", "September", "October", "November", "December"
};

string weekdays[7]={
   "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

int isLeapYear(int year){
    return year%100 == 0? year%400 == 0: year % 4 ==0;
}

int getDays(int year,int month,int day){
    int res = 0;
    for(int i = 1; i < year; i++){
        if(isLeapYear(i))
            res += 366;
        else
            res += 365;
    }
    for(int i = 0; i < month; i++){
        res += days[isLeapYear(year)][i];
    }
    res += day;
    return res;
}

int main(){
    int day1,month1,year1;
    string tmp1,tmp2;
    while(cin>>day1>>tmp1>>year1){
        for(int i = 0; i < 12; i++){
            if(tmp1 == months[i])
                month1 = i + 1;
        }
        int differ = getDays(year1, month1, day1);
        differ = differ % 7;
        cout<<weekdays[differ]<<endl;
    }
    return 0;
}
