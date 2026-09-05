class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,c=0;
        vector<int> a(3,0);
        while(r<s.size()){
            a[s[r]-'a']++;
            while(a[0]>=1&&a[1]>=1&&a[2]>=1){
                c+=s.size()-r;
                a[s[l]-'a']--;
                l++;
            }
            
            r++;
            
        }
        return c;
    }
};