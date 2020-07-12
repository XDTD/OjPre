#include <iostream>
#include<algorithm>
#include<cstring >
#include<vector>
#define INF 0x7fffffff
#define maxN 100
using namespace std;

int mp[maxN][maxN];
int p,n;

int solve(){
    int ans=0;
    int m[maxN];
    memset(m,0,sizeof(m)); //头文件cstring
    int cnt=1,minW;
    vector<int> V;
    V.push_back(1);
    while(cnt<n){
        minW=INF;
        int tmp=1;
        for(int j=0;j<V.size();j++){
            int s=V[j];
            for(int i=2;i<=n;i++){
                if(!m[i]&&minW>mp[s][i]){
                    tmp=i;
                    minW=mp[s][i];
                }
            }
        }
        m[tmp]=1;
        V.push_back(tmp);
        ans+=minW;
        cnt++;
    }
    return ans;
}

int main(){
    while(scanf("%d", &n) && n){
        scanf("%d", &p);
        int a, b, cost;
        for(int i = 0; i < 55; ++i)
            for(int j = 0; j < 55; ++j)
                mp[i][j] = INF;
        for(int i = 0; i < p; ++i)
        {
            scanf("%d%d%d", &a, &b, &cost);
            mp[a][b] = min(mp[a][b], cost);
            mp[b][a] = min(mp[b][a], cost);
        }
        int ans = solve();
        printf("%d\n", ans);
    }
    return 0;
}