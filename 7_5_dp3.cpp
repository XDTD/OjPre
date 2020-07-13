//没搞懂，超时，动态规划
//http://acm.hdu.edu.cn/showproblem.php?pid=1421

#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>

using namespace std;

const int N = 2001;
int weight[N];
int dp[N][N];

int main(){
    int n,k;
    while(scanf("%d %d",&n,&k) != EOF){
        if(n==0) break;
        for(int i = 1;i <= n; i++){
            scanf("%d", &weight[i]);
        }
        sort(weight+1, weight+n);
        for(int i = 0;i <= n;i++) dp[0][i] = 0;
        for(int i = 1;i <= k;i++){
            for(int j = 2 * i;j <= n; j++){
                if(j > 2 *i)
                    dp[i][j] = dp[i][j-1];
                else
                    dp[i][j] = 0x7f;
                int tmp = dp[i][j-2] + pow(weight[j]-weight[j-1],2);
                dp[i][j] = min(dp[i][j],tmp);
            }
        }
        printf("%d\n",dp[k][n]);
    }
    return 0;
}