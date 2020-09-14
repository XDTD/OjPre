#include<iostream>

using namespace std;

long long Fibo(int n){
    if(n == 1 || n == 2) return 1;
    else
        return Fibo(n-1) + Fibo(n-2);
}

int getSum(int n) {
    long long ans = 0;
    for(int i = 1;i <=n; i++){
        for(int j = 1; j <= i; j++){
            for(int k = 1;k <= j; k++){
                ans += Fibo(n);
            }
        }
    }
    long long a = 1000000007;
    ans %= a;
    return ans;
}

int main(){
    int n = 1000000007;
    cout << n <<endl;
}