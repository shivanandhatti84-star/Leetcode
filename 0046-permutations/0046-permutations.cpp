class Solution {
public:
    void fun(vector<vector<int>> &a,vector<int> &nums,int ind){
        if(ind==nums.size()){
            a.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            fun(a,nums,ind+1);
            swap(nums[i],nums[ind]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> a;
        fun(a,nums,0);
        return a;
    }
};