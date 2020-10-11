//Dijkstra
//https://www.nowcoder.com/practice/e372b623d0874ce2915c663d881a3ff2?tpId=63&tqId=29599&tPage=2&ru=/kaoyan/retest/9001&qru=/ta/zju-kaoyan/question-ranking
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

const int N = 1001;
const int M = 100001;
const int INF = 123123;

typedef struct edge{
    int next;
    int dis;
    int cost;
    edge(int _next, int _dis, int _cost): next(_next), dis(_dis), cost(_cost){};
}edge;

vector<edge> edges[N];
int mark[N];
int dis[N];
int costs[N];
int s, t, n, m;


void dijstkra(){
    int next = s;
    dis[next] = 0;
    costs[next] = 0;
    mark[next] = 1;
    for(int i = 1; i < n; i++){    // attention here
        for(int j = 0; j < edges[next].size(); j++){
            int d = edges[next][j].dis + dis[next];
            int c = edges[next][j].cost + costs[next];
            int curNext = edges[next][j].next;
            if(mark[curNext] == 1) continue;
            if(dis[curNext] == -1 || dis[curNext] > d || (dis[curNext] == d && costs[curNext] > c)){
                dis[curNext] = d;
                costs[curNext] = c;
            } 
        }

        int minDis = INF;
        int minCost = INF;
        for(int j = 1; j <= n; j++){ // attention here
            if(mark[j] == 1 || dis[j] == -1) continue;
            if(dis[j] < minDis || (dis[j] == minDis && costs[j] < minCost)){
                minDis = dis[j];
                minCost = costs[j];
                next = j;
            }
        }
        mark[next] = 1;

    }    
}

int main(){
    while(scanf("%d %d", &n, &m) != EOF){
        if(n == 0 && m == 0) break;
        //initial
        for(int i = 0; i < N; i++) edges[i].clear();
        memset(mark, -1, sizeof(mark));
        memset(dis, -1, sizeof(dis));
        memset(costs, -1, sizeof(costs));        
        
        while(m--){
            int a , b, d, p;
            scanf("%d %d %d %d", &a, &b, &d, &p);
            edge temp = edge(b, d, p);
            edges[a].push_back(temp);
            temp.next = a;
            edges[b].push_back(temp);
        }
        scanf("%d %d", &s, &t);
        dijstkra();
        printf("%d %d\n", dis[t], costs[t]);
    }
    return 0;
}

