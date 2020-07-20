//贪心
//http://acm.hdu.edu.cn/showproblem.php?pid=1009
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 1001;

struct item{
    double weitht; 
    double price;
    double v; // 性价比
};

bool cmp(item a, item b){
    return a.v> b.v;
}

int main(){
    int n,m;
    item lists[N];
    while(scanf("%d %d",&n,&m) != EOF){
        if(n==-1 && m==-1) break;
        for(int i = 0; i < m; i++){
            scanf("%lf %lf",&lists[i].weitht,&lists[i].price);
            lists[i].v = lists[i].weitht / lists[i].price;
        }
        sort(lists,lists+m,cmp);
        double ans = 0;
        int cnt = 0;
        while(n > 0&& cnt < m){
            if(n >= lists[cnt].price){
                ans += lists[cnt].weitht;
                n -= lists[cnt].price;
            }else{
                ans += lists[cnt].v * n;
                n = 0;
            }
            cnt++;  //!!
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}