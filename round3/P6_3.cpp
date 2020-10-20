//http://acm.hdu.edu.cn/showproblem.php?pid=1495
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;


struct state{
    int a;
    int b;
    int c;
    int times;
    state(int _a, int _b, int _c, int _times) : a(_a), b(_b), c(_c), times(_times){};
};

const int N = 101;
int vis[N][N][N];

void AtoB(int a, int &na,int b, int &nb){
    if(na + nb >= b){
        na -= (b - nb);
        nb = b;
    }else{
        nb += na;
        na = 0;
    }
}



int BFS(int a, int b, int c){
    state origin = state(a, 0, 0, 0);
    queue<state> Q;
    Q.push(origin);
    vis[a][0][0] = 1;
    while(!Q.empty()){
        state cur = Q.front();
        Q.pop();
        for(int i = 0; i < 6; i++){
            int na = cur.a, nb = cur.b, nc = cur.c;
            switch (i) {
            case 0:
                AtoB(a, na, b, nb);
                break;
            case 1:
                AtoB(a, na, c, nc);
                break;
            case 2:
                AtoB(c, nc, b, nb);
                break;
            case 3:
                AtoB(c, nc, a, na);
                break;
            case 4:
                AtoB(b, nb, a, na);
                break;
            case 5:
                AtoB(b, nb, c, nc);
                break;
            default:
                break;
            }
            if(vis[na][nb][nc] == 1)  continue;
            vis[na][nb][nc] = 1;
            state temp = state(na, nb, nc, cur.times + 1);
            if(na*2 == a && nb*2 == a) return temp.times;
            if(na*2 == a && nc*2 == a) return temp.times;
            if(nb*2 == a && nc*2 == a) return temp.times;
            Q.push(temp);
        }
    }
    return -1;
}

int main(){
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c) != EOF){
        if(a == 0 && b == 0 && c == 0) break;
        memset(vis, 0, sizeof(vis)); //!!!
        int ans = BFS(a, b, c);
        if(ans == -1)
            printf("NO\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}