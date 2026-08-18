class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ar;
        int n=nums.size();
        int mask=1<<n;
        for(int i=0;i<mask;i++){
            vector<int> a;
            for(int j=0;j<nums.size();j++){
                if(i>0 && i&(1<<j) ){
                    a.push_back(nums[j]);
                }
            }
            ar.push_back(a);
        }
        return ar;
    }
};