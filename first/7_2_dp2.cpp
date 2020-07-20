//动态规划，不容易系列，错排公式
//http://acm.hdu.edu.cn/showproblem.php?pid=1465
//错排讲解:https://blog.csdn.net/weixin_39773661/article/details/87859791
#include<cstdio>

const int N = 21;
long long int dp[N];

int main(){
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3; i < N;i++){
        dp[i] = (i-1)*(dp[i-1] + dp[i-2]);
    }
    int n;
    while(scanf("%d",&n) != EOF){
        printf("%lld\n",dp[n]);
    }
    return 0;
}