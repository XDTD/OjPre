//http://acm.hdu.edu.cn/showproblem.php?pid=2064
#include<cstdio>

long long int recursion(int n){
    if(n == 1)
        return 2;
    return 3 * recursion(n - 1) + 2;
}

int main(){
    int n;
    while (scanf("%d", &n) != EOF){
        printf("%lld\n", recursion(n));  // lld, not ld
    }
    return 0;
}