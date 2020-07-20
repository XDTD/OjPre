//贪心算法，今年暑假不AC
//结束条件不能加time<=24!
//http://acm.hdu.edu.cn/showproblem.php?pid=2037

#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 101;

struct item{
    int begin;
    int end;
};

item lists[N];

bool cmp(item a, item b){
    return a.end < b.end;
}

int main(){
    int n;
    while(scanf("%d",&n) != EOF && n!=0){
        for(int i = 0; i < n; i++){
            scanf("%d %d",&lists[i].begin,&lists[i].end);
        }
        sort(lists,lists+n,cmp);
        int ans = 0,time = 0;
        for(int i = 0;i < n ; i++){
            if(lists[i].begin >= time){
                ans++;
                time = lists[i].end;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}