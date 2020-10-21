//important
//http://acm.hdu.edu.cn/showproblem.php?pid=1241

#include<cstdio>
#include<cstring>

const int N = 101;
int mark[N][N];
int isOill[N][N];
int n, m;
int moves[8][2]={
    1, 0,
    1, -1,
    1, 1,
    0, -1,
    0, 1,
    -1, -1,
    -1, 0,
    -1, 1
};

void DFS(int x, int y){
    for(int k = 0; k < 8; k++){
        int nx = x + moves[k][0];
        int ny = y + moves[k][1];
        if(nx < 1 || nx > n || ny < 1 || ny > m)  continue;
        if(mark[nx][ny] == 1 || isOill[nx][ny] == 0) continue;
        mark[nx][ny] = 1;
        DFS(nx, ny);
    }
}



int main(){
    while(scanf("%d %d", &n, &m) != EOF){
        if(n == 0 && m == 0) break;
        memset(mark, 0, sizeof(mark));
        memset(isOill, 0, sizeof(isOill));
        for(int i = 1; i <= n; i++){
            char s[N];
            scanf("%s", s);    
            for(int j = 1; j <= m; j++){
                if(s[j - 1] == '@')
                    isOill[i][j] = 1;
                else
                    isOill[i][j] = 0;
            }
        }
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(isOill[i][j] == 0 || mark[i][j] == 1) continue;
                ans++;
                mark[i][j] = 1; // ????
                DFS(i ,j);     
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}