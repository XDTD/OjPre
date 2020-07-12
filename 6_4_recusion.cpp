//汉诺塔3，注意大数
//http://acm.hdu.edu.cn/showproblem.php?pid=2064
#include<cstdio>

//大数！！
long long int solve(int n){
    if(n == 1)
        return 2;
    else 
        return 3*solve(n-1) + 2;
}

int main(){
    int n;
    while(scanf("%d",&n) != EOF){
        long long int ans = solve(n);
        printf("%lld\n",ans);
    }
    return 0;
}