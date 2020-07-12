//大数乘法，输出格式格式格式格式！！！！！！！！
//https://www.nowcoder.com/practice/f54d8e6de61e4efb8cce3eebfd0e0daa?tpId=60&tqId=29496&tPage=2&ru=/kaoyan/retest/1001&qru=/ta/tsing-kaoyan/question-ranking
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int digit = 10000;  //4位一组
const int N = 10000;     //一共400位
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
        //输出格式
        int flag = 0;  
        for(int i = N-1; i>=0; i--){
            if(nums[i] == 0 && flag == 0) //跳过最开头的零
                continue;
            else if(flag == 0){   //开头不需要补零
                flag = 1;
                printf("%d",nums[i]);
            }else{
                printf("%04d",nums[i]);  //后边要补零
            }
            
        }
        printf("\n");
    }
    return 0;
}