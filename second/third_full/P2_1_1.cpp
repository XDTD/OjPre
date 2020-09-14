//https://www.nowcoder.com/practice/508f66c6c93d4191ab25151066cb50ef?tpId=69&tqId=29657&tPage=1&ru=/kaoyan/retest/11002&qru=/ta/hust-kaoyan/question-ranking
//用库函数的写法


#include<cstdio>
#include<algorithm>

using namespace std;

int main(){
    int nums[101];
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &nums[i]);
        }
        sort(nums, nums+n);
        for(int i = 0; i < n; i++){
            printf("%d ",nums[i]);
        }
        printf("\n");
    }
    return 0;
}