class Solution {
public:
    int fun(vector<int>& nums,int goal){
        int count=0,l=0,r=0;
        while(r<nums.size()){
            if((nums[r]&1)){
                goal--;
            }
                while(l<=r && goal<0){
                    if((nums[l]&1)){
                        goal++;
                    }
                    l++;
                }
            
            count+=r-l+1;
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
};