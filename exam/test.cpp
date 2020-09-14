#include<iostream>

using namespace std;

long long tmp[10000000];

long long FiboInit(int n){
    tmp[1] =1;tmp[2] = 1;
    for(int i = 3; i <= n;i++){
        tmp[i] =(tmp[i-1] + tmp[i-2]) % 1000000007;
    }
}

int getSum(int n) {
    long long ans = 0;
    FiboInit(n);
    for(int i = 1;i <=n; i++){
        for(int j = 1; j <= i; j++){
                for(int k = 1; k <=j ; k++){
                    ans += tmp[k];
                }
        }
    }
    long long a = 1000000007;
    ans %= a;
    return ans;
}

int main(){
    int n = 50;
    cout<<getSum(n)<<endl;
}