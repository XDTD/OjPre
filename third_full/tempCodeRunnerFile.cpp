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
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF){
        if(m == -1 && n == -1) break;
        for(int i = 0; i < n; i++){
            scanf("%lf %lf", &goodsList[i].weight, &goodsList[i].price);
            goodsList[i].costPerformance = goodsList[i].weight / goodsList[i].price;
        }
        sort(goodsList, goodsList + n, cmpGoods);
        int i = 0;
        double ans = 0;
        while(m > 0){
            if(goodsList[i].price < m){
                m -= goodsList[i].price;
                ans += goodsList[i].weight;
            }else{
                ans += (double)m*goodsList[i].costPerformance;
                m = 0;
            }
            i++;
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}