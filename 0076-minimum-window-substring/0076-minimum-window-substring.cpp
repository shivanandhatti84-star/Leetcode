class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> a;
        for(char p:t){
            a[p]++;
        }
        long long l=0,r=0,count=a.size(),minl=INT_MAX,m=0;
        unordered_map<char,int> b;
        while(r<s.size()){
            b[s[r]]++;
            if(a.find(s[r])!=a.end()&&a[s[r]]==b[s[r]]){
                count--;
            }

            while(count<=0&&l<=r){
                if(count==0 && minl>r-l+1){
                minl=min(minl,r-l+1);
                m=l;
                } 
                b[s[l]]--;
                if(a.find(s[l]) != a.end() &&b[s[l]]<a[s[l]]){
                    count++;
                }
                l++;
            
            }
            r++;
        }
        return minl==INT_MAX?"":s.substr(m,minl);
    }
};