//排序题，快排
//https://www.nowcoder.com/practice/508f66c6c93d4191ab25151066cb50ef?tpId=69&tqId=29657&tPage=1&ru=/kaoyan/retest/11002&qru=/ta/hust-kaoyan/question-ranking
#include<cstdio>

const int N = 101;
int nums[N];

void swap(int &a,int &b){
    int tmp = b;
    b = a;
    a = tmp;
}

int partition(int start, int end){
    int pivot = nums[start];
    int idx = start;
    for(int i = start;i < end; i++){
        if(nums[i] < pivot)
            swap(nums[i], nums[++idx]);
    }
    swap(nums[start], nums[idx]);
    return idx;
}

void quick_sort(int start, int end){
    if(start >= end) return ;
    int idx = partition(start, end);
    quick_sort(start, idx);
    quick_sort(idx + 1, end);
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &nums[i]);
        }
        quick_sort(0,n);
        for(int i = 0; i < n; i++){
            printf("%d ",nums[i]);
        }
    }
    return 0;
}