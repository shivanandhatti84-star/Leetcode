class Solution {
public:
    int fun(int num,vector<int> &nums){
        int l=0,r=0,s=0,c=0;
        while(r<nums.size()){
            s+=nums[r];
            while(l<=r && s>num){
                s-=nums[l];
                l++;
            }
            c+=r-l+1;
            r++;
        }
        return c;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // unordered_map<int,int> a;
        // int sum=0,count=0,r=0;
        // a[0]=1;
        // while(r<nums.size()){
            
        //     sum+=nums[r];
        //     if(a.find(sum-goal)!=a.end()){
        //         count+=a[sum-goal];
        //     }
        //     a[sum]++;
        //     r++;
        // }
        // return count;
        return fun(goal,nums)-fun(goal-1,nums);
    }
};