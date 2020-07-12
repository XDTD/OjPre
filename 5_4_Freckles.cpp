//Freckles,最小生成树，Krusgal算法
//https://www.nowcoder.com/practice/41b14b4cd0e5448fb071743e504063cf?tpId=61&tqId=29512&tPage=1&ru=/kaoyan/retest/1002&qru=/ta/pku-kaoyan/question-ranking
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

struct Edge{
    int a;
    int b;
    double cost;
};

struct Point{
    double x;
    double y;
};

const int N = 101;
int Tree[N];
Point points[N];
Edge edges[N*(N-1)/2];


bool cmp(Edge a, Edge b){
    return a.cost<b.cost;
}

double getDistance(Point a,Point b){
    return  sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

int findRoot(int x){
    if(Tree[x] == -1) return x;
    else{
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        memset(Tree,-1,sizeof(Tree));
        for(int i=1;i<= n;i++){
            scanf("%lf %lf",&points[i].x,&points[i].y);
        }
        int m = n*(n-1)/2;
        //计算各边
        int cnt = 0;
        for(int i = 1;i<= n; i++){
            for(int j = i+1;j <= n;j++){
                edges[cnt].a = i;
                edges[cnt].b = j;
                edges[cnt].cost = getDistance(points[i],points[j]);
                cnt++; 
            }
        }        
        sort(edges,edges+m,cmp);
        double ans = 0;
        for(int i = 0;i<m;i++){
            int a = findRoot(edges[i].a);
            int b = findRoot(edges[i].b);
            if(a!=b){
                Tree[a] = b;
                ans+=edges[i].cost;
            }
        }
        printf("%.2lf",ans);
    }
    return 0;
}
