//素数筛法
//https://www.nowcoder.com/practice/7f4be54b37a04fdaa4ee545819151114?tpId=66&tqId=29630&tPage=1&ru=/kaoyan/retest/1004&qru=/ta/buaa-kaoyan/question-ranking
#include<cstdio>
#include<cstring>
#include<cmath>
const int N = 10001;

int isPrime[N];
int primes[N];
int pos;
void init(){
    for(int i = 0; i < N; i++){
        isPrime[i] = 1;
    }
    int bound = sqrt(N);
    for(int i = 2; i < bound; i++){
        if(isPrime[i] == 0) continue;  //attention here, it's continue not break
        for(int j = i * i; j < N; j += i){
            isPrime[j] = 0;
        }
    }
    pos = 0;
    for(int i = 2; i < N; i++){
        if(isPrime[i] == 1 && i%10 == 1){
            primes[pos++] = i; 
        }
    }
}

int main(){
    int n;
    init();
    while (scanf("%d", &n) != EOF){
        for(int i = 0; i < pos && primes[i] < n; i++){
            printf("%d ", primes[i]);
        }
        printf("\n");
    }
    return 0;
}


