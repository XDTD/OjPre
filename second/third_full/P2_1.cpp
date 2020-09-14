//https://www.nowcoder.com/practice/508f66c6c93d4191ab25151066cb50ef?tpId=69&tqId=29657&tPage=1&ru=/kaoyan/retest/11002&qru=/ta/hust-kaoyan/question-ranking
//排序,写的是冒泡

#include<cstdio>

int nums[101];

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}


int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &nums[i]);
        }
        //这里必须有个大循环
        for(int j = 0; j < n;j ++){
            for(int i = 0; i < n-1; i++){
                if(nums[i] > nums[i+1])
                    swap(nums[i], nums[i+1]);
            }
        }
        for(int i = 0; i < n; i++){
            printf("%d ",nums[i]);
        }
        printf("\n");
    }
    return 0;
}