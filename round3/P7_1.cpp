//上楼梯，dp
//https://www.nowcoder.com/practice/c978e3375b404d598f1808e4f89ac551?tpId=69&tqId=29672&tPage=2&ru=/kaoyan/retest/11002&qru=/ta/hust-kaoyan/question-ranking
#include<cstdio>

int main(){
    const int N = 91;
    int n, dp[N];
    dp[1] = 1, dp[2] = 2; 
    for(int i = 3; i < N; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    while (scanf("%d", &n) != EOF){
        printf("%d\n", dp[n]);
    }
    return 0;
}