//http://acm.hdu.edu.cn/showproblem.php?pid=3342
//Legal or Not

#include<cstdio>
#include<cstring>
#include<Queue>
#include<vector>

using namespace std;

const int N = 101;

vector<int> edges[N];
int degree[N];

int main(){
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF){
        if(n == 0 && m == 0) break;
        //initial
        memset(degree, 0, sizeof(degree));
        for(int i = 0; i < N; i++){
            edges[i].clear();
        }

        while(m--){
            int x, y;
            scanf("%d %d", &x, &y);
            degree[y]++;
            edges[x].push_back(y);
        }

        queue<int> Q;
        for(int i = 0; i < n; i++){
            if(degree[i] == 0)
                Q.push(i);
        }

        int cnt = 0;
        while(!Q.empty()){
            int temp = Q.front();
            Q.pop();
            cnt++;
            for(int i = 0; i < edges[temp].size(); i++){
                degree[edges[temp][i]]--;
                if(degree[edges[temp][i]] == 0){
                    Q.push(edges[temp][i]);
                }
            }
        }

        if(cnt == n)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}