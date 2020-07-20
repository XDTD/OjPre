//最大公约数
//https://www.nowcoder.com/questionTerminal/7fd309b4ab854e6e9afda4794b1334a5


#include<cstdio>

//辗转相减法
int gcd(int a,int b){
    while(a!=b){
        if(a > b) a=a-b;
        else      b=b-a;
    }
    return a;
}

int main(){
    int a,b;
    while(scanf("%d %d",&a,&b) != EOF){
        int ans=gcd(a,b);
        printf("%d\n",ans);
    }
    return 0;
}

//除法
/*

int god(int a,int b){
    int ret;
    while(b){
        ret=a%b;
        a=b;
        b=ret;
    }
    return a;
}
*/