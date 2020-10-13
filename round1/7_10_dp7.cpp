//变向的0-1背包问题，珍惜现在，感恩生活，动态规划
//http://acm.hdu.edu.cn/showproblem.php?pid=2191
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct item{
    int weight;
    int val;
};


const int N = 101;
int dp[101];
item list[2001];

int main(){
    int C;
    scanf("%d",&C);
    while(C--){
        int n,m;
        scanf("%d %d",&n,&m);
        int cnt = 0;
        while(m--){
            int p,h,c;
            scanf("%d %d %d",&p,&h,&c);
            while(c--){
                list[cnt].weight =h;
                list[cnt].val = p;
                cnt++;
            }
        }
        memset(dp,0,sizeof(dp));
        for(int i = 0;i < cnt; i++){
            for(int j = n;j >=0; j--){
                if(j - list[i].val>=0){
                    dp[j] = max(dp[j], dp[j - list[i].val] + list[i].weight);
                }
            }
        }
        int ans = 0;
        for(int i = 0;i <= n; i++){
            ans = max(ans, dp[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}
