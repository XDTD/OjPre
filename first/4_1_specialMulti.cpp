//特殊乘法，取余符号应用
//https://www.nowcoder.com/practice/a5edebf0622045468436c74c3a34240f?tpId=60&tqId=29490&tPage=1&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking
#include<cstdio>
using namespace std;

const int N=20;

int main(){
    char a[N],b[N];
    while(scanf("%s %s",a,b)!=EOF){
        int ans=0;
        for(int i = 0;a[i]!=0;i++){
            for(int j = 0;b[j]!=0;j++){
                ans+=(a[i]-'0')*(b[j]-'0');
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

















/*
#include<cstdio>
using namespace std;

const int N=20;

int main(){
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF){
        int n1[N],n2[N];
        int cnt1=0,cnt2=0;
        while(a!=0){
            n1[cnt1++] = a%10;
            a/=10;
        }
        while(b!=0){
            n2[cnt2++] = b % 10;
            b /= 10;
        }
        int ans=0;
        for(int i = 0;i < cnt1;i++){
            for(int j = 0;j < cnt2;j++){
                ans+=n1[i]*n2[j];
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}



*/