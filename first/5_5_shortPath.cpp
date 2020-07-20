//不熟练,最短路径，floyd算法
//http://acm.hdu.edu.cn/showproblem.php?pid=2544
#include<cstdio>
#include<cstring>

const int N = 101;
int ans[N][N];  //邻接矩阵

int main(){
    int n,m;
    while(scanf("%d %d",&n,&m) !=EOF){
        if(n==0 && m==0)
            break;
        memset(ans,-1,sizeof(ans));
        while(m--){
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c);
            ans[a][b] = ans[b][a] = c;
        }
        for(int k=1;k<=n;k++){
            for(int i = 1;i<=n;i++){
                for(int j = 1;j<=n;j++){
                    if(ans[i][k] == -1 || ans[k][j] == -1) continue;
                    else if(ans[i][j] == -1 || ans[i][k] + ans[k][j] < ans[i][j]){
                       ans[i][j]  =ans[i][k] + ans[k][j];
                    }
                }
            }
        }
        printf("%d\n",ans[1][n]);
    }
    return 0;
}