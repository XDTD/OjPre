//动态规划，采药，注意边界和倒序更新
//https://www.nowcoder.com/practice/d7c03b114f0541dd8e32ce9987326c16?tpId=61&tqId=29547&tPage=3&ru=/kaoyan/retest/1002&qru=/ta/pku-kaoyan/question-ranking

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 10000;
int dp[N];
int times[101];
int weight[101];

int main(){
    int T,M;
    while(scanf("%d %d",&T,&M) != EOF){
        for(int i = 0; i < M; i++){
            scanf("%d %d",&times[i],&weight[i]);
        }
        memset(dp,0,sizeof(dp));
        for(int i = 0;i < M; i++){
            for(int j = T;j >=0; j--){    //倒序更新！！！
                if(j - times[i] >= 0)
                    dp[j] = max(dp[j-times[i]] + weight[i],dp[j]);
            }
        }
        int ans = 0;
        for(int i = 0;i <= T; i++){   //边界是T不是T-1
            ans = max(ans,dp[i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}