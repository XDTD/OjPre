#include<string.h>
#include<string>
#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
//https://www.nowcoder.com/practice/0383714a1bb749499050d2e0610418b1?tpId=60&tqId=29474&tPage=1&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking
int n,flag;
struct stu{
    string name;
    int score;
    int order;
};
stu stus[1000];

bool cmp_asc(stu a,stu b){
    if(a.score!=b.score)
        return a.score>b.score;
    else{
        return a.order>b.order;
    }
}
bool cmp_desc(stu a,stu b){
    if(a.score!=b.score)
        return a.score<b.score;
    else{
        return a.order<b.order;
    }
}



int main(){
    int number;
    while(cin>>number>>flag){
        for(int i=0; i<number; i++){
            cin>>stus[i].name>>stus[i].score;
            stus[i].order = i;
        }
        if(flag==0) 
            sort(stus,stus+number,cmp_asc);
        else
            sort(stus,stus+number,cmp_desc);
        for(int j=0; j<number; j++){
            cout<<stus[j].name<<" "<<stus[j].score<<endl;
        }
    }
    return 0;
}