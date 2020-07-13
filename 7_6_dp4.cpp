//动态规划，Greedy Tino，从1开始还是从0开始！！！
//http://acm.hdu.edu.cn/showproblem.php?pid=3578

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int Offset = 2000; //偏移量
int dp[101][4001];
int weight[101];

int main(){
    int T;
    scanf("%d",&T);
    int cas = 0;
    while(T--){
        cas++;
        int n,haveZero = 0;  //重量未为0的柑橘
        scanf("%d",&n);

        for(int i = 1;i <= n; i++){
            scanf("%d",&weight[i]);
            if(weight[i] == 0)
                haveZero = 1;
        }
        memset(dp,-1,sizeof(dp));
        dp[0][Offset] = 0;
        for(int i = 1;i <= n; i++){
            for(int j = -2000;j <= 2000; j++){
                if(j-weight[i] >= -2000 && dp[i-1][j-weight[i]+Offset]!= -1)
                    dp[i][j+Offset] = max(dp[i][j+Offset], dp[i-1][j-weight[i]+Offset]+weight[i]);
                if(j+weight[i] <= 2000  && dp[i-1][j+weight[i]+Offset]!= -1)
                    dp[i][j+Offset] = max(dp[i][j+Offset], dp[i-1][j+weight[i]+Offset]+weight[i]);
                dp[i][j+Offset] = max(dp[i][j+Offset], dp[i-1][j+Offset]);
            }
        }
        int ans = dp[n][0+Offset]/2;
        if(ans == 0)
            printf("Case %d: %d\n",cas,haveZero==1?0:-1);
        else
            printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}

