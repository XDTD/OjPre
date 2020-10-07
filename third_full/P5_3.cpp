//uniom-find problem, some questions
//https://www.nowcoder.com/practice/d6bd75dbb36e410995f8673a6a2e2229?tpId=63&tqId=29595&tPage=2&ru=/kaoyan/retest/9001&qru=/ta/zju-kaoyan/question-ranking

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 101;
const int M = N *(N-1)/2;
struct edge{
    int a;
    int b;
    int cost;
};

edge edges[M]; //attention here
int Tree[N];

bool cmp(edge x, edge y){
    return x.cost < y.cost;
}


int findRoot(int x){
    if(Tree[x] == -1)
        return x;
    else{
        int temp = findRoot(Tree[x]);
        Tree[x] = temp;
        return temp;
    }
}
int main(){
    int n, m;
    while(scanf("%d", &n) != EOF && n != 0){
        memset(Tree, -1, sizeof(Tree));
        m = n * (n-1) / 2;
        for(int i = 1; i <= m; i++){
            scanf("%d %d %d", &edges[i].a, &edges[i].b, &edges[i].cost);
        }
        sort(edges, edges+m, cmp);
        int ans = 0;
        for(int i = 1; i < m; i++){
            edge temp = edges[i];
            int root1 = findRoot(temp.a);
            int root2 = findRoot(temp.b);
            if(root1 != root2){
                ans += temp.cost;
                Tree[root1] = root2;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}




