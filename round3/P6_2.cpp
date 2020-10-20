//http://acm.hdu.edu.cn/showproblem.php?pid=1253
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

struct point{
    int x;
    int y;
    int z;
    int t;
    point(int _x, int _y, int _z, int _t) : x(_x), y(_y), z(_z), t(_t){};
};

int moves[6][3]={
    1, 0, 0,
    -1, 0, 0,
    0, 1, 0,
    0, -1, 0,
    0, 0, -1,
    0, 0, 1
};

const int N = 51;
int a, b, c, t;
int vis[N][N][N];
int isWall[N][N][N];

int BFS(){
    point origin = point(0, 0, 0, 0);
    vis[0][0][0] = 1;
    queue<point> Q;
    Q.push(origin);
    while(!Q.empty()){
        point temp = Q.front();
        Q.pop();
        for(int i = 0; i < 6; i++){
            int nx = temp.x + moves[i][0];
            int ny = temp.y + moves[i][1];    
            int nz = temp.z + moves[i][2];

            if(nx < 0 || nx >= a || ny < 0 || ny >= b || nz < 0 || nz >= c) continue;
            if(vis[nx][ny][nz] == 1 || isWall[nx][ny][nz] == 1) continue;
            point cur = point(nx, ny, nz, temp.t + 1);
            if(nx == a - 1 && ny == b - 1 && nz == c - 1) 
                return cur.t;
            if(cur.t > t)
                return -1; 
            Q.push(cur);
            vis[nx][ny][nz] = 1;
        }
    }
    return -1;
}

int main(){
    int k;
    while(scanf("%d", &k) != EOF){
        while(k--){
            scanf("%d %d %d %d", &a, &b, &c, &t);
            for(int i = 0; i < a; i++){
                for(int j = 0; j < b; j++){
                    for(int m = 0; m < c; m++){
                        scanf("%d", &isWall[i][j][m]);
                    }
                }
            }
            memset(vis, 0, sizeof(vis));
            int ans = BFS();
            printf("%d\n", ans);
        }
    }
    return 0;
}