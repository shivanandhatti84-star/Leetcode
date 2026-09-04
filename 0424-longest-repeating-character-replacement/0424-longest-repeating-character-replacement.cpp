class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> a(26,0);
        int maxl=0,maxc=0,l=0;
        for(int i=0;i<s.size();i++){
            a[s[i]-'A']++;
            maxc=max(maxc,a[s[i]-'A']);
            while(i-l+1-maxc>k){
                a[s[l]-'A']--;
                l++;
            }
            maxl=max(maxl,i-l+1);

        }
        return maxl;
    }
};