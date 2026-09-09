class Solution {
public:
    void maxl(vector<int>& nums,int n,int i){
        int left=2*i+1;
        int right=2*i+2;
        int high=i;
        if(left<n&&nums[left]>nums[i]){
            high=left;
        }
        if(right<n&&nums[right]>nums[high]){
            high=right;
        }
        if(high!=i){
            swap(nums[high],nums[i]);
            maxl(nums,n,high);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        for(int i=nums.size()/2-1;i>=0;i--){
            maxl(nums,nums.size(),i);
        }
        
        for(int i=0;i<k-1;i++){
            swap(nums[0],nums[nums.size()-i-1]);
            maxl(nums,nums.size()-i-1,0);
        }
        return nums[0];
    }
};