//统计同成绩人数
//https://www.nowcoder.com/practice/987123efea5f43709f31ad79a318ca69?tpId=63&tqId=29583&tPage=2&ru=/kaoyan/retest/9001&qru=/ta/zju-kaoyan/question-ranking
#include<iostream>
#include<cstring>

#define N 101
using namespace std;
int scores[N];
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0){
            memset(scores,0,sizeof(scores));
        }
        
        int tmp;
        for(int i=0;i<n;i++){
            scanf("%d",&tmp);
            scores[tmp]++;
        }
        scanf("%d",&tmp); // 目标
        printf("%d",scores[tmp]);    
    }
    return 0;
}