//畅通工程,并查集
//https://www.nowcoder.com/practice/4878e6c6a24e443aac5211d194cf3913?tpId=63&tqId=29573&tPage=1&ru=/kaoyan/retest/9001&qru=/ta/zju-kaoyan/question-ranking
#include<cstdio>

using namespace std;
const int N = 1001;
int Tree[N];

int findRoot(int x){
    if(Tree[x] == -1){
        return x;
    }else{
        int tmp = findRoot(Tree[x]);
        Tree[x] = tmp;
        return tmp;
    }
}

int main(){
    int n,m;
    while(scanf("%d ",&n) !=EOF && n!=0){
        scanf("%d",&m);
        //初始化
        for(int i = 1;i<=n;i++){
            Tree[i] = -1;
        }
        for(int i = 0;i<m;i++){
            int a,b;
            scanf("%d %d",&a,&b);
            a = findRoot(a);
            b = findRoot(b);
            if(a!=b) Tree[a] = b;
        }
        int ans = 0;
        for(int i = 1;i <= n; i++){
            if(Tree[i] == -1)
                ans++;
        }
        printf("%d\n",ans-1);
    }
    return 0;
}