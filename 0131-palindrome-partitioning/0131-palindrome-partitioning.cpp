class Solution {
public:
    bool solve(string &arr){
        int i=0;
        int j=arr.size()-1;
        while(i<j){
            if(arr[i]!=arr[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    void fun(int ind,string &s,vector<vector<string>> &a,vector<string> &ar,string arr){
        if(ind==s.length()){
            a.push_back(ar);
            return;
        }
        for(int i=ind;i<s.length();i++){
            arr=s.substr(ind,i-ind+1);
            if(solve(arr)){
                ar.push_back(arr);
                fun(i+1,s,a,ar,arr);
                ar.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> a;
        vector<string> ar;
        string arr="";
        fun(0,s,a,ar,arr);
        return a;
    }
};