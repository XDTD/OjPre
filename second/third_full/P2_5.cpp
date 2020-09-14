//成绩查询，最基础的Hash
//https://www.nowcoder.com/practice/987123efea5f43709f31ad79a318ca69?tpId=63&tqId=29583&tPage=2&ru=/kaoyan/retest/9001&qru=/ta/zju-kaoyan/question-ranking

#include<cstdio>
#include<cstring>

const int N = 101;

int main(){
    int score[N], n;
    int temp;
    while(scanf("%d", &n) != EOF && n != 0){
        memset(score, 0, sizeof(score));
        for(int i = 0; i < n; i++){
            scanf("%d", &temp);
            score[temp]++;
        }
        scanf("%d", &temp);
        printf("%d\n", score[temp]);
    }
    return 0;
}