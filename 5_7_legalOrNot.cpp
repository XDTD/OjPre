//拓补排序，Legal or Not
//http://acm.hdu.edu.cn/showproblem.php?pid=3342
#include<cstdio>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

const int N = 501;
vector<int> edges[N];
int degree[N];


int main(){
    int n,m;
    while (scanf("%d %d",&n,&m) != EOF){
        if(n==0 && m==0) 
            break;
        //初始化
        for(int i=0;i<N;i++) 
            edges[i].clear();
        memset(degree,0,sizeof(degree));
        while(m--){
            int a,b;
            scanf("%d %d", &a, &b);
            degree[b]++;
            edges[a].push_back(b);
        }
        //遍历
        queue<int> Q;
        for(int i=0;i<n;i++){
            if(degree[i] == 0)
                Q.push(i);
        }
        int cnt = 0;
        while(!Q.empty()){
            int tmp = Q.front();
            Q.pop();
            cnt++;
            for(int i = 0;i < edges[tmp].size(); i++){
                degree[edges[tmp][i]]--;
                if(degree[edges[tmp][i]] == 0)
                    Q.push(edges[tmp][i]);
            }
        }
        if(cnt == n)
            printf("YES\n");
        else
            printf("NO\n");       
    }
    return 0;
}