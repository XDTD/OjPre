//贪心算法，今年暑假不AC
//http://acm.hdu.edu.cn/showproblem.php?pid=2037

#include<iostream>
#include<algorithm>
#define N 100
using namespace std;
struct Program{
    int begin;  //开始时间
    int end;    //结束时间
};

Program buf[N];
int n;

bool cmp(Program a,Program b){
    return a.end<b.end;
}

int main(){
    while(cin>>n&&n!=0){
        for(int i=0;i<n;i++){
            cin>>buf[i].begin>>buf[i].end;
        }
        sort(buf,buf+n,cmp);
        int ans=0,time=0;
        for(int i=0;i<n;i++){
            if(buf[i].begin>=time){
                ans++;
                time=buf[i].end;
            }
        }
        cout<<ans<<endl;
    }
}