//BFS，非常可乐，注意倒可乐时候变量变化的顺序
//http://acm.hdu.edu.cn/showproblem.php?pid=1495
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>

using namespace std;

struct point{
    int x,y,z;//分别代表瓶子、和两个杯子里的可乐体积
    int t;  //代表倒的次数
    point(int a,int b,int c,int d):x(a),y(b),z(c),t(d){}
};

const int N = 101;
int mark[N][N][N];



void AtoB(int &a,int &sa,int &b,int &sb){
    if(a <= sb - b){   //顺序！！！
        b += a;
        a = 0;
    }else{
        a = a -(sb -b);
        b = sb;
    }
}

int BFS(int sa,int sb,int sc){
    queue<point> Q;
    point s(sa,0,0,0);
    Q.push(s);
    while(!Q.empty()){
        point now = Q.front();
        Q.pop();
        int a,b,c;
        a = now.x;
        b = now.y;
        c = now.z;
        AtoB(a,sa,b,sb); // a倒b
        if(mark[a][b][c] != 1){
            mark[a][b][c] = 1;
            point tmp(a,b,c,now.t + 1);
            Q.push(tmp);
            if(a*2 == sa &&b*2==sa) return tmp.t;
            if(a*2 == sa &&c*2==sa) return tmp.t;
            if(b*2 == sa &&c*2==sa) return tmp.t;
        }
        a = now.x;
        b = now.y;
        c = now.z;
        // b倒a
        AtoB(b,sb,a,sa); 
        if(mark[a][b][c] != 1){
            mark[a][b][c] = 1;
            point tmp(a,b,c,now.t + 1);
            Q.push(tmp);
            if(a*2 == sa &&b*2==sa) return tmp.t;
            if(a*2 == sa &&c*2==sa) return tmp.t;
            if(b*2 == sa &&c*2==sa) return tmp.t;
        }

        a = now.x;
        b = now.y;
        c = now.z;
        // a倒c
        AtoB(a,sa,c,sc); 
        if(mark[a][b][c] != 1){
            mark[a][b][c] = 1;
            point tmp(a,b,c,now.t + 1);
            Q.push(tmp);
            if(a*2 == sa &&b*2==sa) return tmp.t;
            if(a*2 == sa &&c*2==sa) return tmp.t;
            if(b*2 == sa &&c*2==sa) return tmp.t;
        }
        a = now.x;
        b = now.y;
        c = now.z;
        AtoB(c,sc,a,sa); // c倒a
        if(mark[a][b][c] != 1){
            mark[a][b][c] = 1;
            point tmp(a,b,c,now.t + 1);
            Q.push(tmp);
            if(a*2 == sa &&b*2==sa) return tmp.t;
            if(a*2 == sa &&c*2==sa) return tmp.t;
            if(b*2 == sa &&c*2==sa) return tmp.t;
        }
        a = now.x;
        b = now.y;
        c = now.z;
        // b倒c
        AtoB(b,sb,c,sc); 
        if(mark[a][b][c] != 1){
            mark[a][b][c] = 1;
            point tmp(a,b,c,now.t + 1);
            Q.push(tmp);
            if(a*2 == sa &&b*2==sa) return tmp.t;
            if(a*2 == sa &&c*2==sa) return tmp.t;
            if(b*2 == sa &&c*2==sa) return tmp.t;
        }
        // c倒b  
        a = now.x;
        b = now.y;
        c = now.z;
        AtoB(c,sc,b,sb);
        if(mark[a][b][c] != 1){
            mark[a][b][c] = 1;
            point tmp(a,b,c,now.t + 1);
            Q.push(tmp);
            if(a*2 == sa &&b*2==sa) return tmp.t;
            if(a*2 == sa &&c*2==sa) return tmp.t;
            if(b*2 == sa &&c*2==sa) return tmp.t;
        }
    }
    return -1;
}

int main(){
    int sa,sb,sc;
    while(scanf("%d %d %d",&sa,&sb,&sc) != EOF){
        memset(mark,0,sizeof(mark));
        if(sa==0 && sb==0 && sc==0) break;
        int ans = BFS(sa,sb,sc);
        if(ans == -1)
            printf("NO\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}