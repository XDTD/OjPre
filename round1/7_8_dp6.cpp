
















/*  贪心算法只过了测试数据
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

struct List{
    double weight;
    double val;
    double x; //性价比
};


const int N = 10001;
int dp[N];
List lists[501];

bool cmp(List a,List b){
    return a.x < b.x;
}

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
            scanf("%lf %lf",&lists[i].val, &lists[i].weight);
            lists[i].x = lists[i].val / lists[i].weight;
        }
        memset(dp,0,sizeof(dp));
        int ans = 0;
        sort(lists,lists+n,cmp);
        for(int i = 0;i < n; i++){
            int tmp = upper / lists[i].weight;
            if(tmp > 0){
                ans += tmp * lists[i].val;
                upper -= tmp * lists[i].weight;
            }
        }
        if(upper != 0){
            printf("This is impossible.\n");
        }else{
            printf("The minimum amount of money in the piggy-bank is %d.\n",ans);
        }

    }
    return 0;
}

*/