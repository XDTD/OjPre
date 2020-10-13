//最长公共子序列，LCS
//https://www.nowcoder.com/practice/f38fc44b43cf44eaa1de407430b85e69?tpId=62&tqId=29471&tPage=2&ru=/kaoyan/retest/2002&qru=/ta/sju-kaoyan/question-ranking

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 101;
char s1[N];
char s2[N];
int dp[N][N];

int main(){
    while(scanf("%s %s",s1,s2) != EOF){
        int len1 = strlen(s1),len2 = strlen(s2);
        int ans = 0;
        for(int i = 0;i < len1; i++) dp[i][0] = 0;
        for(int j = 0;j < len2; j++) dp[0][j] = 0;
        for(int i = 1;i <= len1; i++){
            for(int j = 1; j <= len2; j++){
                if( s1[i -1] == s2[j -1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                ans = max(ans,dp[i][j]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}