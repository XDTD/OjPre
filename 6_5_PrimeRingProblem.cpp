//枚举回溯，递归实现，Prime Ring Problem
//Presentation Error，注意输出格式！！
#include<cstdio>
#include<cstring>

using namespace std;
int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41};
int ans[21];
int vis[21];
int n;

bool isPrime(int x){
    for(int i = 0;i < 13; i++){
        if(x == primes[i])
            return true;
    }
    return false;
}

void check(){
    if(isPrime(ans[0] + ans[n-1])){
        for(int i = 0; i < n;i++){
            printf("%d",ans[i]);
            if(i != n-1)
                printf(" ");    //输出格式！！！！
        }
        printf("\n");
    }
    
}

void DFS(int cnt){
    if(cnt > 1 && !isPrime(ans[cnt-1] + ans[cnt-2]) ){   //用！而不是~
        return ;
    }
    if(cnt == n){
        check();
        return;
    }
    for(int i = 2;i <= n; i++){
        if(vis[i] == 1) continue;
        vis[i] = 1;
        ans[cnt] = i;
        DFS(cnt+1);
        vis[i] = 0;  
    }
    
}

int main(){
    int cases = 0;
    while(scanf("%d",&n) != EOF){
        cases++;
        memset(vis,0,sizeof(vis));
        ans[0] = 1;
        vis[1] = 1;
        printf("Case %d:\n",cases);
        DFS(1);
        printf("\n");   //输出格式！！！
    }
    return 0;
}