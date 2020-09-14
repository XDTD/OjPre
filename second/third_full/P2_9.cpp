//简单的查找并不需要排序二分
//https://www.nowcoder.com/questionTerminal/069e2130430c41229ab25e47fa0949a6
#include<cstdio>

const int N = 201;

int nums[N];
int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &nums[i]);
        }
        int target;
        scanf("%d", &target);
        int ans = -1;
        for(int  i = 0;i < n; i++){
            if(nums[i] == target){
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}




/*   误以为的需要排序二分版本
#include<cstdio>
#include<algorithm>

using namespace std;

const int N = 201;
int nums[N];

int binSearch(int x, int n){
    int l = 0, r = n - 1;
    int mid, ans = -1;
    while(l <= r){
        mid = (l + r) / 2;
        if(x < nums[mid])
            r = mid - 1;
        else if(x > nums[mid])
            l = mid + 1;
        else{
            ans = mid;
            break;  
        }
    }
    return ans;
}


int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &nums[i]);
        }
        sort(nums,nums + n);
        int target;
        scanf("%d", &target);
        int idx = binSearch(target, n);
        printf("%d\n", idx);
    }
    return 0;
}


 */