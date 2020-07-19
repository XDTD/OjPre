//解决，DFS，注意回溯和剪枝
//http://acm.hdu.edu.cn/showproblem.php?pid=1010
#include<cstdio>
#include<cstring>

const int N = 10;
int vis[N][N];
char mp[N][N];
int sx,sy; //起点
int ex,ey; //终点
int n,m,T; //n行m列时长T
int move[][2] = {
    -1,0,
    1,0,
    0,-1,
    0,1
};

int DFS(int x,int y,int t){
    if(x == ex && y == ey && t == T)
        return 1;
    for(int i = 0; i<4; i++){
        int nx = x + move[i][0];
        int ny = y + move[i][1];  //别TM写错了
        if(nx >= 0 && ny >= 0 && nx < n&& ny < m && !vis[nx][ny] && mp[nx][ny]!='X'){
            vis[nx][ny] = 1;
            if(DFS(nx, ny , t+1))
                return 1;
            vis[nx][ny] = 0;
        }
    }  
    return 0;
}

int main(){
    while (scanf("%d %d %d",&n,&m,&T) != EOF){
        if(n == 0 && m==0 && T==0) break;
        memset(vis,0,sizeof(vis));
        for(int i = 0; i < n; i++){
            scanf("%s",mp[i]);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mp[i][j] == 'D'){
                    ex = i;
                    ey = j;
                }
                if(mp[i][j] == 'S'){
                    sx = i;
                    sy = j;
                    vis[sx][sy] = 1;
                }
            }
        }
        if( (ex + ey) % 2 != (sx + sy + T) %2){
            printf("NO\n");
        }else{
            if(DFS(sx, sy, 0)){
                printf("YES\n");
            }else{
                printf("NO\n");
            }
        }
    }
    return 0;
}