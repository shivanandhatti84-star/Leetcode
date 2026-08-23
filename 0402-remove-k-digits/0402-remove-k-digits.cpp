class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans="";
        stack<char> st;
        for(int i=0;i<num.size();i++){
            while(!st.empty()&&st.top()-'0'>num[i]-'0'&&k>0){
                st.pop();
                k--;
                
            }
             st.push(num[i]);
        }
        while(!st.empty()&&k>0){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        if(!ans.size()) return "0";
        while(ans.size()>0&&ans.back()=='0'&&ans!="0"){
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
   
};