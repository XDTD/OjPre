//最小公倍数，注意溢出问题
//https://www.nowcoder.com/questionTerminal/d077de5c3623407b953bfdf49843dd43
#include<cstdio>

int gcd(int a,int b){
    while(a != b){
        if(a > b) a = a-b;
        else b = b -a;
    }
    return a;
}

int main(){
    int a,b;
    while(scanf("%d %d",&a,&b) != EOF){
        int ans=a/gcd(a,b)*b;    //注意顺序防止溢出！！！！
        printf("%d\n",ans);
    }
    return 0;
}