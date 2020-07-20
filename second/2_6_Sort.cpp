//第k大的数
//https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

class Solution {
public:

    int partition(vector<int>& nums,int start,int end){
        int pivot = nums[start];
        int idx = start;
        for(int i = start; i < end; i++){
            if(nums[i] > pivot)
                swap(nums[i], nums[++idx]);
        }
        swap(nums[start], nums[idx]);
        return idx;
    }

    int quickSort(vector<int>& nums,int start,int end,int k){
        int idx = partition(nums,start,end);
        if(idx == k)
            return nums[k];
        return idx < k? quickSort(nums,idx+1,end,k):quickSort(nums,start,idx,k);
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quickSort(nums,0,nums.size(),k-1);
    }
};