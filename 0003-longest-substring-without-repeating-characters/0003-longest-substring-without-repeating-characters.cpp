class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> a(256,0);
        int maxl=0;
        int i=0,j=0;
        while(i<s.size()){
            if(a[s[i]]==0){
                
                a[s[i]]++;
                maxl=max(maxl,i-j+1);
                i++;
            }
            else{
                a[s[j]]--;
                j++;
            }
        }
       return maxl; 
    }
};