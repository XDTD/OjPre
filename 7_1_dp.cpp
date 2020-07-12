//动态规划，N阶上楼梯问题，有手就行
//https://www.nowcoder.com/practice/c978e3375b404d598f1808e4f89ac551?tpId=69&tqId=29672&tPage=2&ru=/kaoyan/retest/11002&qru=/ta/hust-kaoyan/question-ranking
#include<cstdio>

const int N = 91;
int dp[N];

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2;i < n; i++){
            dp[i] = dp[i-1] + dp[i -2];
        }
        printf("%d\n",dp[n-1]);
    }
    return 0;
}