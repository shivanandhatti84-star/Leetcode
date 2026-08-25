class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> a(256,0);
        int maxl=0,count=0;
        int i=0,j=0;
        while(i<s.size()){
            if(a[s[i]]==0){
                count++;
                a[s[i]]++;
                maxl=max(maxl,count);
                i++;
            }
            else{
                count--;
                a[s[j]]--;
                j++;
            }
        }
       return maxl; 
    }
};