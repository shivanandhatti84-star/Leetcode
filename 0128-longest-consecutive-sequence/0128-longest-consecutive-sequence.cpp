// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         if(nums.size()==0) return 0;
        
//         unordered_set<int> mapl(nums.begin(), nums.end());
     
//         int maxl=1;
//         for(int i=0;i<nums.size();i++){
//             if(mapl.find(nums[i]-1)!=mapl.end()) continue;
//             int count=1;
//             int x=nums[i];
//             while(mapl.find(x+1)!=mapl.end()){
//                 count++;
                
//                 x++;
//             }
//             maxl=max(maxl,count);
//         }
//         return maxl;
//     }
// };

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        // Use a set to instantly remove duplicates and save memory
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxl = 1;
        
        // Iterate directly through unique numbers to avoid duplicate calculations
        for (int num : numSet) {
            // Check if it's the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {
                int count = 1;
                int x = num;
                
                while (numSet.find(x + 1) != numSet.end()) {
                    count++;
                    x++;
                }
                maxl = max(maxl, count);
            }
        }
        return maxl;
    }
};
