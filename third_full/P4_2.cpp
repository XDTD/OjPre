//注意为零的特殊case
//https://www.nowcoder.com/practice/9255c05d45b8406c9b588d7c57aa920b?tpId=63&tqId=29582&tPage=1&ru=/kaoyan/retest/9001&qru=/ta/zju-kaoyan/question-ranking
#include<cstdio>
#include<cstring>
const int N = 100;
int num[N];
int main(){
    int m, a, b;
    while(scanf("%d", &m) != EOF){
        scanf("%d %d", &a, &b);
        long long temp = a + b;
        int i = 0;
        do{
            num[i++] = temp % m;
            temp /= m;
        }while((temp != 0));
        while(i > 0){
            printf("%d", num[--i]);
        }
        printf("\n");
    }
    return 0;
}