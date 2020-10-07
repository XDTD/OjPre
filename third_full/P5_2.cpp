#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N = 10000001;
int Tree[N];
int sum[N];

int findRoot(int x){
    if(Tree[x] == -1){
        return x;
    }else{
        int temp = findRoot(Tree[x]);
        Tree[x] = temp;
        return temp;
    }
}


int main(){
    int n;
    while (scanf("%d", &n) != EOF){
        memset(sum, 0, sizeof(sum));
        memset(Tree, -1, sizeof(Tree));
        while(n--){
            int a, b;
            scanf("%d %d", &a, &b);
            a = findRoot(a);
            b = findRoot(b);
            if(a != b){
                Tree[b] = a;
                sum[a] = sum[a] + sum[b] + 1; 
            }
        }
        int ans = 0;
        for(int i = 1; i < N; i++){
            ans = max(ans, sum[i] + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}