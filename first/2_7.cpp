#include<cstring>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
//https://www.nowcoder.com/practice/a3417270d1c0421587a60b93cdacbca0?tpId=62&tqId=29465&tPage=1&ru=/kaoyan/retest/2002&qru=/ta/sju-kaoyan/question-ranking
int dayTab[2][13]={
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

string months[] = {"","January","February","March","April","May","June","July","August","September","October","November","December"};
 
string weekdays[] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
 

int isLeapYear(int year){
    return year%100==0?year%400==0:year%4==0;
}

int main(){
    int year,month,day;
    string tmp;
    while(cin>>day>>tmp>>year){
        for(int i=0;i<13;i++){
            if(months[i]==tmp)
                month=i;
        }
        int cnt=0;
        for(int i=1;i<year;i++){
            if(isLeapYear(i))
                cnt+=366;
            else
                cnt+=365;
        }
        for(int i=0;i<month;i++){
            if(isLeapYear(year))
                cnt+=dayTab[1][i];
            else
                cnt+=dayTab[0][i];
        }
        cnt+=day;
        int idx=(cnt-1)%7;
        cout<<weekdays[idx]<<endl;
    }
    return 0;
}
