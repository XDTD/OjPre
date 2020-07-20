//统计同成绩人数
//https://www.nowcoder.com/practice/987123efea5f43709f31ad79a318ca69?tpId=63&tqId=29583&tPage=2&ru=/kaoyan/retest/9001&qru=/ta/zju-kaoyan/question-ranking

#include<cstdio>
#include<cstring>

const int N  = 101;
int scores[N];

int main(){
    int n;
    while(scanf("%d",&n) !=EOF && n!=0){
        int tmp;
        memset(scores,0,sizeof(scores));
        while(n--){
            scanf("%d",&tmp);
            scores[tmp]++;
        }
        scanf("%d",&tmp);
        printf("%d\n",scores[tmp]);
    }
    return 0;
}