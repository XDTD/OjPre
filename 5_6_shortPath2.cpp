// 没掌握,最短路径，dijskra算法
//https://www.nowcoder.com/practice/e372b623d0874ce2915c663d881a3ff2?tpId=63&tqId=29599&tPage=2&ru=/kaoyan/retest/9001&qru=/ta/zju-kaoyan/question-ranking
#include<cstdio>
#include<math.h>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge{
    int a;   //下一跳
    int len;  //长度
    int cost;  //花费
};

const int N = 1001;
const int INF = 0x7fffffff;
int dis[N];
int costs[N];
int vis[N];  //是否已经访问
int s,t;  //起点终点
int n,m; 
vector<Edge> edges[N]; 


void dijskra(){
    int next = s;  //初始化为起点
    vis[next] = 1;
    dis[next] = 0;
    costs[next] = 0;
    for(int i = 1;i < n ; i++){   //从1开始！！
        for(int j = 0;j<edges[next].size(); j++){
            Edge tmp = edges[next][j]; 
            if(vis[tmp.a] == 1) continue;
            else{
                //注意注意注意！！！！！！！！
                if( dis[next]+tmp.len < dis[tmp.a] || dis[tmp.a] == -1){
                    dis[tmp.a] = dis[next]+tmp.len;
                    costs[tmp.a] = costs[next] +tmp.cost;
                }else if(dis[tmp.a]  ==  dis[next]+tmp.len &&  costs[next] +tmp.cost < costs[tmp.a]){
                    dis[tmp.a] = dis[next]+tmp.len;
                    costs[tmp.a] = costs[next] +tmp.cost;
                }
            }
        }
        int minTmpLen = INF;
        int minTmpCost = INF;
        for(int j = 1;j <= n;j++){
            if(vis[j] != 1 && dis[j] != -1){
                if(dis[j] < minTmpLen || (dis[j] == minTmpLen && costs[j] < minTmpCost)){
                    minTmpLen = dis[j];
                    minTmpCost = costs[j];
                    next = j;
                }
            }
        }
        vis[next] = 1;
    }
}

int main(){
    while(scanf("%d %d",&n,&m) != EOF){
        //初始化
        if(n==0 && m==0) break;
        for(int i = 0;i< N;i++){
            edges[i].clear();
        }
        memset(dis,-1,sizeof(dis));
        memset(vis,-1,sizeof(vis));
        memset(costs,-1,sizeof(costs));
        while(m--){
            int a,b,l,c;
            scanf("%d %d %d %d",&a,&b,&l,&c);
            Edge tmp;
            tmp.len = l;
            tmp.cost =c;
            tmp.a = a;
            edges[b].push_back(tmp);
            tmp.a = b;
            edges[a].push_back(tmp);
        }
        scanf("%d %d",&s,&t);
        dijskra();
        printf("%d %d\n",dis[t] ,costs[t]);   //注意！
    }
    return 0;
}