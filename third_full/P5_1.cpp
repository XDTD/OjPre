//union-find
//https://www.nowcoder.com/practice/4878e6c6a24e443aac5211d194cf3913?tpId=63&tqId=29573&tPage=1&ru=/kaoyan/retest/9001&qru=/ta/zju-kaoyan/question-ranking
#include<cstdio>
#include<cstring>

const int TreeSize = 1001;
int Tree[TreeSize];

int findRoot(int x){
    if(Tree[x] == -1)
        return x;
    else{
        int temp = findRoot(Tree[x]);
        Tree[x] = temp;
        return temp;
    }
}

int main(){
    int N, M;
    while(scanf("%d %d", &N, &M) != EOF && N != 0){
        memset(Tree, -1, sizeof(Tree));
        while(M--){
            int a, b;
            scanf("%d %d", &a, &b);
            a = findRoot(a);
            b = findRoot(b);
            if(a != b)  Tree[a] = b;
        }
        int ans = 0;
        for(int i = 1; i <= N; i++){
            if(Tree[i] == -1)
                ans++;
        }
        printf("%d\n", ans-1);
    }
    return 0;
}