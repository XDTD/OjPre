#include<cstdio>

int nums[101];

vector<int> getPrimes(){
    const int N = 10000000;
    int mark[N];
    memset(mark,0,sizeof(mark));
    for(int i = 2;i <N; i++){
        if(mark[i] == 1) continue;
        else{
            for(int j = i*i; j < N; j+=i){
                mark[i] = 1;
            }
        }
    }
    vector<int> res;
    for(int i = 2;i < N; i++){
        if(mark[i] == 0) 
            res.push_back(i);
    }
    return res;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int  i = 0; i < n; i++){
            scanf("%d", &nums[i]);
        }
        printf("%d\n",n/2);
    }
    return 0;
}