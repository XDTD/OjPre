//FatMouse' Trade
//http://acm.hdu.edu.cn/showproblem.php?pid=1009
//贪心算法
#include<iostream>
#include<algorithm>
#include<cstdio>
#define maxM 1000
using namespace std;
struct goods{
    double Weight; //总重
    double price;  //价格
    double s;      //性价比
};

double N;  //double!
int M;
goods buf[maxM];

bool cmp(goods a,goods b){
    return a.s>b.s;
}

int main(){
    while(cin>>N>>M &&N!=-1){
        for(int i=0;i<M;i++){
            cin>>buf[i].Weight>>buf[i].price;
            buf[i].s=buf[i].Weight/buf[i].price;
        }
        sort(buf,buf+M,cmp);
        double ans=0;
        for(int i=0;i<M&&N>0;i++){
            if(N>=buf[i].price){
                N-=buf[i].price;
                ans+=buf[i].Weight;
            }else{
                ans=ans+N*buf[i].s;
                N=0;
            }
        }
        printf("%.3lf\n",ans);  //格式！
    }
    return 0;
}