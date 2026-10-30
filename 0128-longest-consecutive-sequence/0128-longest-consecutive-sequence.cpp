class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        
        unordered_set<int> mapl(nums.begin(), nums.end());
     
        int maxl=1;
        for(int num:mapl){
            if(mapl.find(num-1)!=mapl.end()) continue;
            int count=1;
            int x=num;
            while(mapl.find(x+1)!=mapl.end()){
                count++;
                
                x++;
            }
            maxl=max(maxl,count);
        }
        return maxl;
    }
};

