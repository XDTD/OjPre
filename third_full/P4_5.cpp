//最大公倍数
//https://www.nowcoder.com/questionTerminal/d077de5c3623407b953bfdf49843dd43
#include<cstdio>

int gcd(int a,int b){
    while(a != b){
        if(a > b) a -= b;
        else b -= a;
    }
    return a;
}

int main(){
    int a, b;
    while(scanf("%d %d", &a ,&b) != EOF){
        printf("%d\n", a / gcd(a, b) * b);
    }
    return 0;
}