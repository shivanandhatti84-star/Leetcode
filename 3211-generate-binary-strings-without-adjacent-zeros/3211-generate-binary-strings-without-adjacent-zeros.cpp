class Solution {
public:
    void help(vector<string>* shi,string s,int n){
    if (s.length() == n) {
        shi->push_back(s);
        return;
    }

    help(shi,s+'1',n);

    if (s.empty() || s.back() != '0') {
        help(shi,s + "0",n);
    }
        
    }
    vector<string> validStrings(int n) {
        vector<string> shi;
        string s="";
        help(&shi,s,n);
        return shi;
    }
};
