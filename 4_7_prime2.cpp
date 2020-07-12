//素数，输入一个整数n(2<=n<=10000)，要求输出所有从1到这个整数之间(不包括1和这个整数)个位为1的素数，如果没有则输出-1。
//https://www.nowcoder.com/practice/7f4be54b37a04fdaa4ee545819151114?tpId=66&tqId=29630&tPage=1&ru=/kaoyan/retest/1004&qru=/ta/buaa-kaoyan/question-ranking
#include<cstdio>
#include<math.h>
#include<cstring>
const int N=10001;

int mark[N];
int primes[N];// 素数数组
int cnt;
void init(){
    memset(mark,0,sizeof(mark));
    for(int i=2;i<N;i++){
        if(mark[i] == 1) 
            continue;
        else{
            for(int j=i*i;j<N;j+=i){
                mark[j] = 1 ;
            }
        }
    }
    cnt=0;
    for(int i=2;i<N;i++){
        if(mark[i] == 0 && i%10 == 1){
            primes[cnt++]=i;
        }
    }
}

int main(){
    int n;
    init();
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<cnt;i++){
            if(primes[i]<n){
                printf("%d ",primes[i]);
            }
        }
        printf("\n");
    }
    return 0;
}