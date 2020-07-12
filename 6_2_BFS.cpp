//BFS,胜利大逃亡，输入问题
//http://acm.hdu.edu.cn/showproblem.php?pid=1253
#include<cstdio>
#include<cstring>
#include<queue>

using namespace std;

struct point{
    int x,y,z;
    int t;
    point(int a1,int a2,int a3,int a4):x(a1),y(a2),z(a3),t(a4){}
};

const int N = 51;
int mark[N][N][N]; //是否访问
int isWall[N][N][N];  //是不是墙

//步长
int moves[6][3]={
    -1,0,0,
    0,-1,0,
    0,0,-1,
    1,0,0,
    0,1,0,
    0,0,1
};


//a,b,c城堡大小
int BFS(int a,int b,int c,int t){
    queue<point> Q;
    mark[0][0][0] = 1;
    point s(0,0,0,0);  //起点
    Q.push(s);
    while(!Q.empty()){
        point now = Q.front();
        Q.pop();
        for(int i = 0; i < 6; i++){
            int nx = now.x + moves[i][0];
            int ny = now.y + moves[i][1];
            int nz = now.z + moves[i][2];
            if(nx<0 || ny<0 || nz<0 ||nx>=a ||ny>=b ||nz>=c) continue;
            if(mark[nx][ny][nz] == 1) continue;
            if(isWall[nx][ny][nz] == 1) continue;
            point tmp(nx,ny,nz,now.t+1);
            Q.push(tmp);
            mark[nx][ny][nz] = 1;
            if(tmp.t > t)
                return -1;
            if(nx==a-1 && ny==b-1 && nz==c-1) 
                return tmp.t;
        }
    }
    return -1;
}

int main(){
    int n,a,b,c,t;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d %d %d",&a,&b,&c,&t);
        //初始化
        memset(mark,0,sizeof(mark));
        memset(isWall,0,sizeof(isWall));
        for(int i = 0;i < a;i++){
            for(int j = 0;j<b; j++){
                for(int k = 0; k < c; k++){
                    scanf("%d",&isWall[i][j][k]);   //输入牛批
                }
            }
        }
        int ans = BFS(a,b,c,t);
        printf("%d\n",ans);
    }
    return 0;
}