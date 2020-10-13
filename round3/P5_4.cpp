//https://www.nowcoder.com/practice/41b14b4cd0e5448fb071743e504063cf?tpId=61&tqId=29512&tPage=1&ru=/kaoyan/retest/1002&qru=/ta/pku-kaoyan/question-ranking
//
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

struct point{
    double x;
    double y;
    int root;
};

struct edge{
    int point1;
    int point2;
    double dis;
};


const int N = 101;
const int sizeOfEdge = (N-1) * N / 2;
point points[N];
edge edges[sizeOfEdge];

double getDistance(point a, point b){
    return sqrt((a.x- b.x) *(a.x- b.x)  + (a.y-b.y) * (a.y-b.y));
}

int findRoot(int x){
    if(points[x].root == -1){
        return x;
    }else{
        int temp = findRoot(points[x].root);
        points[x].root = temp;
        return temp;
    }
}

bool cmp(edge a, edge b){
    return a.dis < b.dis;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n; i++){
            double a, b;
            scanf("%lf %lf", &points[i].x, &points[i].y);
            points[i].root = -1;
        }
        int m = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                edges[m].point1 = i;
                edges[m].point2 = j;
                edges[m].dis = getDistance(points[i], points[j]);
                m++;
            }
        }
        double ans = 0;
        sort(edges, edges + m, cmp);
        for(int i = 0; i < m; i++){
            int root1 = findRoot(edges[i].point1);
            int root2 = findRoot(edges[i].point2);
            if(root1 != root2){
                ans += edges[i].dis;
                points[root1].root = root2;
            }
        }
        printf("%.2f\n", ans);
    }
}


