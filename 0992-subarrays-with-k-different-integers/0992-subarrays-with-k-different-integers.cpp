class Solution {
public:
    int fun(vector<int> &nums,int k){
        int r=0,l=0,count=0;
        unordered_map<int,int> a;
        while(r<nums.size()){
            a[nums[r]]++;
            while(a.size()>k){
                a[nums[l]]--;
                if(a[nums[l]]==0){
                    a.erase(nums[l]);
                }
                l++;
            }
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
};