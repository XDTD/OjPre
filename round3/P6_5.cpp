//http://acm.hdu.edu.cn/showproblem.php?pid=1016
//presentention error
#include<cstdio>
#include<cstring>

const int N = 21;
int primes[13] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
int n;
int vis[N];
int ans[N];

int isPrime(int x){
    for(int i = 0; i < 13; i++){
        if(x == primes[i])
            return 1;
    }
    return 0;
}

void check(){
    if(isPrime(ans[0] + ans[n-1])){
        for(int i = 0; i < n; i++){
            printf("%d", ans[i]);
            if(i != n-1)
                printf(" ");            
        }
        printf("\n");
    }
}

void DFS(int cnt){
    if(cnt > 1 && !isPrime(ans[cnt-1] + ans[cnt-2]))
        return;
    if(cnt == n){
        check();
        return;
    }
    for(int i = 2; i <= n; i++){
        if(vis[i] == 1) continue;
        vis[i] = 1;
        ans[cnt] = i;
        DFS(cnt + 1);
        vis[i] = 0;
    }
}

int main(){
    int cases = 0;
    while (scanf("%d", &n) != EOF){
        memset(vis, -1, sizeof(0));
        ans[0] = 1;
        vis[1] = 1;
        printf("Case %d:\n", ++cases);
        DFS(1);      // attention here  
        printf("\n");   // attention here 
    }
    return 0;
}