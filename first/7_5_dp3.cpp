//动态规划,状态转移，INF！！
//http://acm.hdu.edu.cn/showproblem.php?pid=1421

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 2001;
const int INF = 0x7fffffff;
int dp[N][N];
int list[N];



int main(){
    int n,k;
    while(scanf("%d %d",&n,&k) != EOF){
        for(int i = 1; i <= n; i++){
            scanf("%d", &list[i]);
        }
        sort(list+1,list + n + 1);  //排序
        for(int i = 0; i < n; i++) {
            dp[i][0] = 0;
            for(int j = 1; j <= k; j++){
                dp[i][j] = INF;
            }
        }
        for(int i = 1;i <= n; i++){
            for(int j = 1; j <= min(k,i/2); j++){
                dp[i][j] = min(dp[i-1][j], dp[i-2][j-1] + (list[i]-list[i-1])*(list[i]-list[i-1]));
            }
        }
        printf("%d\n",dp[n][k]);
    }
    return 0;
}