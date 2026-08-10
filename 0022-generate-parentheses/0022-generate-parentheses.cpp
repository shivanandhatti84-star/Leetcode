class Solution {
public:
    void help(vector<string>* sh,int open,int close,string s,int n){
        if(s.length()==2*n){
            sh->push_back(s);
            return;
        }
        if(open<n) help(sh,open+1,close,s+'(',n);
        if(close<open) help(sh,open,close+1,s+')',n);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> sh;
        string s="";
        help(&sh,0,0,s,n);
        return sh;
    }
};