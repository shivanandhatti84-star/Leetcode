class Solution {
public:
    void fun(int n,int k,vector<vector<int>> &ar,vector<int> &a,int ind){
        if(n==0&&k==a.size()){
            ar.push_back(a);
            return;
        }
        if(n<0||a.size()>k) return;
        for(int i=ind;i<10;i++){
            if(i<=n){
                a.push_back(i);
                fun(n-i,k,ar,a,i+1);
                a.pop_back();
            }
            else{
                break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ar;
        vector<int> a;
        fun(n,k,ar,a,1);
    return ar;
    }
};