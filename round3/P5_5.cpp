//http://acm.hdu.edu.cn/showproblem.php?pid=2544
#include<cstdio>
#include<cstring>

const int N = 101;
int dp[N][N];

int main(){
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF){
        if(n == 0 && m == 0) break;
        memset(dp, -1, sizeof(dp));       
        while(m--){
            int a, b;
            scanf("%d %d ", &a, &b);
            scanf("%d", &dp[a][b]);
            dp[b][a] = dp[a][b];
        }
        for(int k = 1; k <= n; k++){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if(dp[i][k] == -1 || dp[k][j] == -1) continue;
                    else if(dp[i][j] == -1 || dp[i][k] + dp[k][j] < dp[i][j]){
                        dp[i][j] = dp[i][k] + dp[k][j];
                    }
                }
            }
        }
        printf("%d\n", dp[1][n]);
    }
    return 0;
}