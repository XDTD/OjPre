//完全背包问题，Piggy-Bank,贪心过了测试数据，动态规划AC
//http://acm.hdu.edu.cn/showproblem.php?pid=1114

#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct List{
    int weight;
    int val;
};


const int N = 10001;
const int INF = 0x7fffffff;
int dp[N];
List lists[501];



int main(){
    int T;
    int E,F; //储蓄罐空重量和当前重量
    int n;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&E,&F);
        int upper = F -E;
        scanf("%d",&n);
        for(int i = 0; i<n; i++){
            scanf("%d %d",&lists[i].val, &lists[i].weight);
        }
        for(int i = 0;i <= upper;i++) dp[i] = INF;
        dp[0] = 0;
        for(int i = 0;i <n; i++ ){
            for(int j = lists[i].weight; j<= upper; j++){
                if(dp[j - lists[i].weight] != INF){
                    dp[j] = min(dp[j], dp[j - lists[i].weight] + lists[i].val);
                }
            }
        }
        
        
        if(dp[upper] == INF){
            printf("This is impossible.\n");
        }else{
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[upper]);
        }

    }
    return 0;
}