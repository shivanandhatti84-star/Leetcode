class Solution {
    private:
    void fun(vector<int>& nums,vector<vector<int>> &ar,vector<int> &a,int ind){

            ar.push_back(a);
    
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            a.push_back(nums[i]);
            fun(nums,ar,a,i+1);
            a.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ar;
        vector<int> a;
        sort(nums.begin(),nums.end());
        fun(nums,ar,a,0);
        return ar;
    }
};