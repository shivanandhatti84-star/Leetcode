class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> a;
        int sum=0,count=0,r=0;
        a[0]=1;
        while(r<nums.size()){
            
            sum+=nums[r];
            if(a.find(sum-goal)!=a.end()){
                count+=a[sum-goal];
            }
            a[sum]++;
            r++;
        }
        return count;
    }
};