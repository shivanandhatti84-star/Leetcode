class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r,c=0;
        vector<int> a(3,0);
        for(r=0;r<s.size();r++){
            a[s[r]-'a']++;
            while(a[0]>=1&&a[1]>=1&&a[2]>=1){
                c+=s.size()-r;
                a[s[l]-'a']--;
                l++;
            }
        }
        return c;
    }
};