class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<bool> dp(n+1,false);
        dp[0]=true;
        int min_c = INT_MAX;
int max_c = 0;

for(auto &word : wordDict) {
    
    min_c = min(min_c, (int)word.size());
    max_c = max(max_c, (int)word.size());
}
        for(int i=min_c;i<=n;i++){
            for(int j=i; j >= max(0, i - max_c);j--){
                if(dp[j]&&dict.count(s.substr(j,i-j))){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};