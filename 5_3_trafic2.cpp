//还是畅通工程，并查集，最小生成树，Kruskal算法牛逼
//https://www.nowcoder.com/practice/d6bd75dbb36e410995f8673a6a2e2229?tpId=63&tqId=29595&tPage=2&ru=/kaoyan/retest/9001&qru=/ta/zju-kaoyan/question-ranking
//重点再来
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct  Edge{
    int a;
    int b;
    int cost;

    bool operator <(const Edge &x) const{
        return  cost<x.cost;
    }
};

Edge edge[6000];
int Tree[101];

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
    while(scanf("%d",&n) != EOF &&n!=0){
        memset(Tree,-1,sizeof(Tree));
        int m = n*(n-1)/2;
        for(int i = 0;i<m;i++){
            int a,b,cost;
            scanf("%d %d %d",&a,&b,&cost);
            edge[i].a = a;edge[i].b = b; edge[i].cost = cost;
        }
        sort(edge,edge+m);
        int ans = 0;
        for(int i =0 ;i<m;i++){
            int a = findRoot(edge[i].a);
            int b = findRoot(edge[i].b);
            if(a!=b){
                Tree[a] = b;
                ans += edge[i].cost;
            }
        }
        printf("%d\n",ans);
    }
    return  0;
}