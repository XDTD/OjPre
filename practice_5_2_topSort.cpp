//拓补排序，确认比赛名次
//注意Output Limit Exceeded，以及小顶堆头文件
//http://acm.hdu.edu.cn/showproblem.php?pid=1285
#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<functional>  //包含进去
using namespace std;

const int N = 501;
int degree[N];
vector<int> edges[N];
vector<int> ans;



int main(){
    int n,m;
    while(scanf("%d %d",&n,&m) != EOF){
        if(n==0 && m==0)
            break;
        //初始化
        memset(degree,0,sizeof(degree));
        for(int i = 0;i<N;i++)
            edges[i].clear();
        ans.clear();    //注意！！！！！！！！！

        while(m--){
            int a,b;
            scanf("%d %d",&a,&b);
            edges[a].push_back(b);
            degree[b]++;
        }

        //遍历
        priority_queue<int,vector<int>,greater<int>>  Q;
        int cnt = 0 ;
        for(int i = 1;i <= n; i++){
            if(degree[i] == 0)
                Q.push(i);
        }
        while(!Q.empty()){
            int tmp = Q.top();
            ans.push_back(tmp);  //存储结果
            Q.pop();
            for(int i = 0; i < edges[tmp].size(); i++){
                degree[edges[tmp][i]]--;
                if(degree[edges[tmp][i]] == 0)
                    Q.push(edges[tmp][i]);
            }
        }
        //输出
        for(int i = 0;i < ans.size(); i++){
            if( i == ans.size() - 1)
                printf("%d\n",ans[i]);
            else
                printf("%d ", ans[i]);
        }
    }
    return 0;
}