// class Solution {
// public:
//     int fun(vector<int> &nums,int k){
//         int r=0,l=0,count=0;
//         unordered_map<int,int> a;
//         while(r<nums.size()){
//             a[nums[r]]++;
//             while(a.size()>k){
//                 a[nums[l]]--;
//                 if(a[nums[l]]==0){
//                     a.erase(nums[l]);
//                 }
//                 l++;
//             }
//             count+=r-l+1;
//             r++;
//         }
//         return count;
//     }
//     int subarraysWithKDistinct(vector<int>& nums, int k) {
//         return fun(nums,k)-fun(nums,k-1);
//     }
// };






class Solution {
public:
    int fun(vector<int> &nums,int k){
        int r=0,l=0,count=0;
        vector<int> a(nums.size()+1,0);
        while(r<nums.size()){
            if(a[nums[r]]==0){
                k--;
                
            }
            a[nums[r]]++;
            while(k<0){
                a[nums[l]]--;
                if(a[nums[l]]==0){
                    k++;
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