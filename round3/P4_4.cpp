//最大公约数
//https://www.nowcoder.com/questionTerminal/7fd309b4ab854e6e9afda4794b1334a5
#include<cstdio>

int gcd(int a, int b){
    if(a < b) return gcd(b, a);
    if(a == b) return a;
    return gcd(a-b, b);
}

int main(){
    int a, b;
    while(scanf("%d %d", &a, &b) != EOF){
        printf("%d\n", gcd(a, b));
    }
    return 0;
}