//质因数的个数，注意大质因子
//https://www.nowcoder.com/practice/20426b85f7fc4ba8b0844cc04807fbd9?tpId=60&tqId=29479&tPage=1&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking
#include<cstdio>
#include<cstring>
const int N=10000;


int prime[N]; //质数
int mark[N];  //标记
int cnt;


void init(){
    memset(mark,0,sizeof(mark));
    for(int i=2;i<N;i++){
        if(mark[i]==1) 
            continue;
        else{
            for(int j=i*i;j<N;j+=i){
                mark[j] = 1;
            }
        }
    }
    cnt = 0;
    for(int i=2;i<N;i++){
        if(mark[i] == 0){
            prime[cnt++] = i;
        }
    }
}


int main(){
    int n;
    init();
    while(scanf("%d", &n) != EOF ){
        int ans=0;
        for(int i=0;i<cnt;i++){
            while(n%prime[i]==0){
                ans++;
                n/=prime[i];
            }
        }
        if(n!=1)     ///重要！！！！，大质因子
            ans++;
        printf("%d\n",ans);
    }
    return 0;
}