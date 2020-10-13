//The more the better，并查集，注意结果
//https://acm.njupt.edu.cn/problem/NOJ1810
#include<cstdio>
#include<algorithm>

using namespace std; 
const int N = 10000001;

int Tree[N];
int sum[N];

int findRoot(int x){
    if(Tree[x] == -1) return x;
    else{
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        for(int i = 1;i<=N ;i++){
            Tree[i] = -1;
            sum[i] = 0;
        }
        
        for(int i = 0;i < n; i++){
            int a,b;
            scanf("%d %d",&a,&b);
            a = findRoot(a);
            b = findRoot(b);
            if(a!=b){
                Tree[a] = b;
                sum[b] = sum[a] + sum[b] +1;
            }
        }
        int ans = 0;
        for(int i = 1;i<=N ; i++){
            ans = max(ans, sum[i]);
        }
        printf("%d\n",ans+1);  //注意！
    }
    return 0;
}