//继续畅通工程，最小生成树，kruskgal算法，并查集
#include<cstdio>
#include<cstring>
#include<math.h>
#include<algorithm>
using namespace std;

typedef struct Edge{
    int a;
    int b;
    int cost;
    void set(int a1,int a2,int a3){
        a = a1;
        b = a2;
        cost = a3;
    }
}Edge;

const int N = 101;
const int M = N*(N-1)/2;
int Tree[N];
Edge edge0[M];  //没修好的
Edge edge1[M];  //修好的

bool cmp(Edge a,Edge b){
    return a.cost<b.cost;
}
int findRoot(int x){
    if(Tree[x] == -1)
        return x;
    else{
        int tmp = findRoot(Tree[x]);
        Tree[x] =  tmp;
        return tmp;
    }
}

int main(){
    int n;
    while(scanf("%d",&n) != EOF && n!=0){
        memset(Tree,-1,sizeof(Tree));
        int m = n*(n-1)/2;
        int cnt0 = 0,cnt1 = 0;  
        for(int i = 0;i<m;i++){
            int a,b,cost,flag;
            scanf("%d %d %d %d",&a,&b,&cost,&flag);
            if(flag == 0){
                edge0[cnt0++].set(a,b,cost);
            }else{
                edge1[cnt1++].set(a,b,cost);
            }
        }
        sort(edge0,edge0+cnt0,cmp);
        sort(edge1,edge1+cnt1,cmp);
        int ans = 0;
        for(int i = 0;i<cnt1;i++){
            int a = findRoot(edge1[i].a);
            int b = findRoot(edge1[i].b);
            if(a!=b){
                Tree[a] = b;
            }
        }
        for(int i = 0;i<cnt0;i++){
            int a = findRoot(edge0[i].a);
            int b = findRoot(edge0[i].b);
            if(a!=b){
                Tree[a] = b;
                ans+=edge0[i].cost;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
