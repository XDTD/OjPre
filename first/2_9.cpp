//数组中的第K个最大元素
//https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
//思路快排
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parttion(vector<int>& nums,int start,int end){
    int pivot=nums[start];
    int idx=start;
    for(int i=start+1;i<end;i++){
        if(pivot<=nums[i])
            swap(nums[++idx],nums[i]);
    }
    swap(nums[idx],nums[start]);
    return idx;
}

int quickSlect(vector<int>& nums,int start,int end,int k){
    int idx=parttion(nums,start,end);
    if(idx==k)
        return nums[k];
    else
        return idx<k?quickSlect(nums,idx+1,end,k):quickSlect(nums,start,idx,k); 
}

int findKthLargest(vector<int>& nums, int k) {
    return quickSlect(nums,0,nums.size(),k-1);
}

int main(){
    vector<int> nums={3,2,3,1,2,4,5,5,6};
    int ans=findKthLargest(nums,4);
    cout<<ans<<endl;
    return 0;
}
