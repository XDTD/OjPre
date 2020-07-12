//查找学生信息
//https://www.nowcoder.com/practice/fe8bff0750c8448081759f3ee0d86bb4?tpId=60&tqId=29499&tPage=2&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking
#include<iostream>
#include<algorithm>
#include<string>
#define maxN 1000
#define maxM 10000
using namespace std;


struct Student{
    string idx;
    string name;
    string sex;
    int age;
};

Student stus[maxN];
string nums[maxM];
int N,M;

bool cmp(Student a,Student b){
    return a.idx<b.idx;
}

int binSearch(string idx){
    int l=0,r=N;
    int target=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(stus[mid].idx==idx){
            target=mid;
            break;
        }
        else if(stus[mid].idx<=idx) l=mid+1;
        else r=mid-1;
    }
    return target;
}


int main(){
    while(cin>>N){
        for(int i=0;i<N;i++){
            cin>>stus[i].idx>>stus[i].name>>stus[i].sex>>stus[i].age;
        }
        sort(stus,stus+N,cmp);
        cin>>M;
        for(int i=0;i<M;i++){
           cin>>nums[i];
        }
        for(int i=0;i<M;i++){
           int tmp=binSearch(nums[i]);
           if(tmp!=-1){
               Student a=stus[tmp];
               cout<<a.idx<<" "<<a.name<<" "<<a.sex<<" "<<a.age<<endl;
           }else{
               cout<<"No Answer!"<<endl;
           }
           
        }
    }
    return 0;
}