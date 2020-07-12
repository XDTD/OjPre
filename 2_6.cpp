#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
//https://www.nowcoder.com/practice/ccb7383c76fc48d2bbc27a2a6319631c?tpId=62&tqId=29468&tPage=2&ru=/kaoyan/retest/2002&qru=/ta/sju-kaoyan/question-ranking
int dayTable[2][13]={
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

bool isLeapYear(int year){
    return year%100==0?year%400==0:year%4==0;
}



int main(){
    char a[9],b[9];
    int year1,month1,day1;
    int year2,month2,day2;
    while(cin>>a>>b){
        sscanf(a,"%4d%2d%2d",&year1,&month1,&day1);
        sscanf(b,"%4d%2d%2d",&year2,&month2,&day2);
        int cnt1=0,cnt2=0;
        for(int i=0;i<year1;i++){
            if(isLeapYear(i))
                cnt1+=366;
            else
                cnt1+=365;
        }
        for(int i=0;i<month1;i++){
            if(isLeapYear(year1))
                cnt1+=dayTable[1][i];
            else
                cnt1+=dayTable[0][i];
        }
        cnt1+=day1;
        for(int i=0;i<year2;i++){
            if(isLeapYear(i))
                cnt2+=366;
            else
                cnt2+=365;
        }
        for(int i=0;i<month2;i++){
            if(isLeapYear(year2))
                cnt2+=dayTable[1][i];
            else
                cnt2+=dayTable[0][i];
        }
        cnt2+=day2;
        cout<<abs(cnt1-cnt2)+1<<endl;
    }
    return 0;
}