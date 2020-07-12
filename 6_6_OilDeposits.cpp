//图的遍历，DFS,Oil Deposits,注意相邻的定义和下标
//http://acm.hdu.edu.cn/showproblem.php?pid=1241
#include<cstdio>
#include<cstring>
const int N = 101;
char maze[N][N];
int mark[N][N];
int move[][2]={  //注意相邻的定义
    -1,0,
    1,0,
    0,1,
    0,-1,
    1,1,
    1,-1,
    -1,-1,
    -1,1
};
int m,n;

void DFS(int x,int y){  //别瞎写下标。。
    for(int i = 0;i < 8;i++){
        int nx = x + move[i][0];
        int ny = y + move[i][1];
        if(nx < 1 || nx >n || ny < 1 || ny > m) continue;
        if(maze[nx][ny] == '*') continue;
        if(mark[nx][ny] == 1) continue;
        mark[nx][ny] = 1;    //忘了标记就是无线循环
        DFS(nx,ny);
    }
}

int main(){
    while(scanf("%d %d",&n,&m) != EOF){
        if(n==0 && m==0) break;
        memset(mark,0,sizeof(mark));
        for(int i = 1;i <= n; i++){
            scanf("%s",maze[i]+1);   //行和列都是从1到n
        }
        int ans = 0;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <=m; j++){
                if(maze[i][j] == '*' || mark[i][j] ==1) continue;
                ans++;
                mark[i][j] = 1;
                DFS(i,j);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}