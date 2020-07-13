//最长递增子序列，LIS,拦截导弹
//https://www.nowcoder.com/practice/dad3aa23d74b4aaea0749042bba2358a?tpId=61&tqId=29549&tPage=3&ru=/kaoyan/retest/1002&qru=/ta/pku-kaoyan/question-ranking
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 26;
int height[N];
int dp[N];
int main(){
    int k;
    while(scanf("%d",&k) != EOF){
        for(int i = 0;i < k;i++){
            scanf("%d",&height[i]);
        }
        memset(dp,0,sizeof(dp));
        int hMax;
        dp[0] = 1;
        for(int i = 0;i < k;i++){
            hMax = 1;  //初始化的位置
            for(int j = 0;j < i; j++){
                if(height[j] >= height[i])
                    hMax = max(hMax, dp[j]+1);
            }
            dp[i] = hMax;
        }
        int ans = 1;
        for(int i = 0; i < k; i++){
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}