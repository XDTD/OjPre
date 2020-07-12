//未解决,WA
//http://acm.hdu.edu.cn/showproblem.php?pid=1010
#include<cstdio>
#include<cstring>

const int N = 8;
char maze[N][N];
int mark[N][N];
int n,m,t;
int sx,sy; //终点
bool flag; //是否到达终点

int move[][2]={
    -1,0,
    1,0,
    0,1,
    0,-1
};

void DFS(int x,int y,int time){
    for(int i = 0; i < 4; i++){
        int nx = x + move[i][0];
        int ny = y + move[i][1];
        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
        if(maze[nx][ny] == 'X' || mark[nx][ny] == 1) continue;
        mark[nx][ny] = 1;
        if(nx == sx && ny == sy ) {
            if(time + 1 == t){
                flag = true;
                return;
            }
            else continue;
        }    
        DFS(nx,ny,time+1);
        mark[nx][ny] = 0;
        if(flag) return;
    }
}

int main(){
    while(scanf("%d %d %d",&n,&m,&t) != EOF){
        if(n==0 && m==0 && t==0) break;
        for(int i = 1; i <= n;i++){
            scanf("%s",maze[i]+1);
        }
        //初始化
        memset(mark,0,sizeof(mark));
        flag = false;

        //找终点
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m; j++){
                if(maze[i][j] == 'D'){
                    sx = i;
                    sy = j;
                    break;
                }
            }
        }
        //找起点
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= m; j++){
                if(maze[i][j] == 'S'){
                    //奇偶性是否满足
                    if((i+j)%2 ==(sx+sy+t)%2){
                        mark[i][j] = 1;
                        DFS(i,j,0);
                    }
                    break;
                }
            }
        }
        if(flag==1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
