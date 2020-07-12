#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int digit = 10000;  //4位一组
const int N = 30;     //一共120位
int nums[N];

void bigIntergerMultiple(int n){
    memset(nums,0,sizeof(nums));
    nums[0] = 1;
    for(int i = 2;i <= n; i++){
        int next = 0 ,tmp = 0;
        for(int j = 0;j < N; j++){
            nums[j] = nums[j] * i + next ;
            next =  nums[j] / digit;
            nums[j] %= digit;
        }
    }
}



int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        bigIntergerMultiple(n);
        for(int i = N-1; i>=0; i--){
            if(nums[i] == 0) 
                continue;
            printf("%d",nums[i]);
        }
        printf("\n");
    }
    return 0;
}