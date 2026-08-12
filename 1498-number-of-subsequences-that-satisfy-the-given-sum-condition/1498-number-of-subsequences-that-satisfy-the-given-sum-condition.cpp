class Solution {
public:
        
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1000000007;
        if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int left=0;
        long long ans=0;
        vector<long long> pow(nums.size());
        pow[0]=1;
        for(int i=1;i<nums.size();i++){
            pow[i]=(pow[i-1]*2)%MOD;
        }

        int right=nums.size()-1;

        while(left<=right){
            if(nums[left]+nums[right]<=target){
                ans=(ans+pow[right-left])%MOD;
                left++;
            }
            else{
                right--;
            }
        }
        return (int)ans;
    }
};