//FatMouse' Trade，贪心算法
//注意double和结束条件
//http://acm.hdu.edu.cn/showproblem.php?pid=1009

#include<cstdio>
#include<algorithm>

using namespace std;
const int N = 1001;

struct goods{
    double price;
    double weight;
    double costPerformance;
};

goods goodsList[N];

bool cmpGoods(goods a, goods b){
    return a.costPerformance > b.costPerformance;
}

int main(){
    double m;
    int n;
    while(scanf("%lf %d", &m, &n) != EOF){
        if(m == -1 && n == -1) break;
        for(int i = 0; i < n; i++){
            scanf("%lf %lf", &goodsList[i].weight, &goodsList[i].price);
            goodsList[i].costPerformance = goodsList[i].weight / goodsList[i].price;
        }
        sort(goodsList, goodsList + n, cmpGoods);
        int i = 0;
        double ans = 0;
        while(m > 0 && i < n){  // 没说钱一定用完，fk
            if(goodsList[i].price <= m){
                m -= goodsList[i].price;
                ans += goodsList[i].weight;
            }else{
                ans = ans + m*goodsList[i].costPerformance;
                m = 0;
            }
            i++;
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}