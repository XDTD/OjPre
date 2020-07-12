#include<cstdio>
#include<algorithm>
#define N 100

using namespace std;
int nums[N];
int n;
//排序题，快排
//https://www.nowcoder.com/practice/508f66c6c93d4191ab25151066cb50ef?tpId=69&tqId=29657&tPage=1&ru=/kaoyan/retest/11002&qru=/ta/hust-kaoyan/question-ranking
int partition(int start,int end){
    int pivot=nums[start];
    int idx=start;
    for(int i=start+1;i<end;i++){
        if(pivot>nums[i]){
             swap(nums[++idx],nums[i]);
        }
    }
    swap(nums[idx],nums[start]);
    return idx;
}

void quickSort(int start,int end){
    if(start>=end)
        return;
    int pivot=partition(start,end);
    quickSort(start,pivot);
    quickSort(pivot+1,end);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&nums[i]);
    }
    quickSort(0,n);
    for(int i=0;i<n;i++){
        printf("%d ",nums[i]);
    }
    return 0;
}