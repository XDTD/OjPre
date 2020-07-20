//大数加法，没啥问题,有另一种解法
//https://www.nowcoder.com/practice/4c39c984ea3848b48e111b8e71ec1dd4?tpId=69&tqId=29656&tPage=1&ru=/kaoyan/retest/11002&qru=/ta/hust-kaoyan/question-ranking
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;
const int N = 1001;
char s1[N];
char s2[N];
int nums[N];

int main(){
    while(scanf("%s %s",s1,s2) != EOF){
        int len1 = strlen(s1), len2 = strlen(s2);
        memset(nums,0,sizeof(nums));
        for(int i = len1-1;i>=0;i--){
            nums[len1-1-i] += s1[i] -'0';
        }
        for(int i = len2-1;i>=0;i--){
            nums[len2-1-i] += s2[i] -'0';
        }
        int flag = 0 , len =max(len1, len2);
        for(int i = 0;i<len;i++){
            nums[i] += flag;
            flag = nums[i] /10;
            nums[i] %= 10;
        }
        //输出
        for(int i = len-1 ;i>=0; i--){
            printf("%d",nums[i]);
        }
        printf("\n");
    }
    return 0;
}
