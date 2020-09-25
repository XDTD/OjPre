//质因数的个数
//https://www.nowcoder.com/practice/20426b85f7fc4ba8b0844cc04807fbd9?tpId=60&tqId=29479&tPage=1&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking

#include<cstdio>
#include<cmath>
const int N = 100001;
int isPrime[N];
int primes[N];
int pos;

void init(){
    for(int i = 0; i < N; i++){
        isPrime[i] = 1;
    }
    int bound = sqrt(N);
    for(int i = 2; i < bound; i++){
        if(isPrime[i] == 0) continue;
        for(int j = i * i; j < N; j += i){
            isPrime[j] = 0;
        }
    }
    pos = 0;
    for(int i = 2;i < N; i++){
        if(isPrime[i] == 1 ){
            primes[pos++] = i;
        }
    }
}


int main(){
    int n;
    init();
    while(scanf("%d", &n) != EOF){
        int ans = 0;
        for(int i = 0; i < pos; i++){
            if(n < primes[i]) break;
            while(n % primes[i] == 0){
                n /= primes[i];
                ans++;
            }
        }
        if(n != 1)
            ans++;
        printf("%d\n",ans);
    }
}
