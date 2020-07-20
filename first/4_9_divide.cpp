//整除问题
//https://www.nowcoder.com/practice/8e29045de1c84d349b43fdb123ab586a?tpId=62&tqId=29462&tPage=1&ru=/kaoyan/retest/2002&qru=/ta/sju-kaoyan/question-ranking
#include<cstdio>
#include<cstring>

#define min(a,b)  a<b?a:b
const int N=1001;
const int INF = 0x7fffffff; 
int primes[N];
int primeOfn[N];
int primeOfa[N];

int mark[N];
int cnt; //N以内的质因数个数

void init(){
    memset(mark,0,sizeof(mark));
    for(int i=2;i<N;i++){
        if(mark[i] == 1)
            continue;
        else{
            for(int j = i * i;j < N;j += i ){   //当初莫名其妙的bug
                mark[j] = 1;
            }
        }
    }
    cnt = 0;
    for(int i = 2; i < N; i++){
        if(mark[i] == 0){
            primes[cnt++] = i;
        }
    }
}

//得到 n 和 a的质因子
void getPrimeFactor(int n,int a){
    //重置
    memset(primeOfn,0,sizeof(primeOfn));
    memset(primeOfa,0,sizeof(primeOfa));
    for(int i = 0;i < cnt; i++){
        while(a % primes[i] == 0){
            primeOfa[primes[i]]++;
            a /= primes[i];
        }
        
    }
    for(int j=2;j<=n;j++){
        int tmp=j;
        for(int i=0;i<cnt;i++){
            while(tmp% primes[i] == 0){
                primeOfn[primes[i]]++;
                tmp /= primes[i];
            }
        }   
    }
}

int main(){
    int n,a;
    init();
    while(scanf("%d %d", &n, &a) != EOF){
        getPrimeFactor(n,a);
        int ans=INF;
        for(int i=0;i<N;i++){
            if(primeOfa[i] == 0) continue;
            else{
                ans = min(primeOfn[i]/primeOfa[i], ans);  //注意顺序
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}