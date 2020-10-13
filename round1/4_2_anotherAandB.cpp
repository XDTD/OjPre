//又一版A+B,进制转换，注意溢出和边界情况
//https://www.nowcoder.com/practice/9255c05d45b8406c9b588d7c57aa920b?tpId=63&tqId=29582&tPage=1&ru=/kaoyan/retest/9001&qru=/ta/zju-kaoyan/question-ranking

#include<cstdio>
const int N=20;

int main(){
    long long a,b;
    int m;
    while(scanf("%d %lld %lld ",&m,&a,&b)!=EOF&&m!=0){
        int nums[N];
        long long tmp=a+b;
        int cnt=0;
        while(tmp!=0){
            nums[cnt++]=tmp%m;
            tmp/=m;
        }
        if(cnt==0)   //特殊情况
            printf("%d\n",0);
        for(int i=cnt-1;i>=0;i--){
            printf("%d",nums[i]);
        }
         printf("\n");
    }
    return 0;
}
