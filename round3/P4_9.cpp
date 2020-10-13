//注意素数因子的表示方式和n的阶乘
//https://www.nowcoder.com/practice/8e29045de1c84d349b43fdb123ab586a?tpId=62&tqId=29462&tPage=1&ru=/kaoyan/retest/2002&qru=/ta/sju-kaoyan/question-ranking
#include<cstdio>
#include<cmath>
#include<cstring>

#define min(a, b) a < b ? a : b
const int N = 1001;

int isPrime[N];
int primes[N];
int primesOfN[N];
int primesOfA[N];
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
    for(int i = 2; i < N; i++){
        if(isPrime[i] == 1){
            primes[pos++] = i;
        }
    }
}

void getPrimes(int a, int n){
    memset(primesOfA, 0 , sizeof(primesOfA));
    memset(primesOfN, 0 , sizeof(primesOfN));


    for(int i = 0; i< pos; i++){
        if(a == 1) break;
        while(a % primes[i] == 0){
            primesOfA[primes[i]]++;
            a /= primes[i];
        }
    }


    //这里不能用累乘的方法，溢出 溢出和复杂度问题
    for(int j = 2; j <= n; j++){
        int tmp = j;
        for(int i = 0; i < pos;i++){
            while(tmp% primes[i] == 0){
                primesOfN[primes[i]]++;
                tmp /= primes[i];
            }
        }   
    }

    
}


int main(){
    int n, a;
    init();
    while(scanf("%d %d", &n, &a) != EOF){
        getPrimes(a, n);
        int k = n;
        for(int i = 0; i < pos; i++){
            if(primesOfA[i] == 0) continue;
            k = min(k, primesOfN[i] / primesOfA[i]);
        }
        printf("%d\n", k);
    }
    return 0;
}