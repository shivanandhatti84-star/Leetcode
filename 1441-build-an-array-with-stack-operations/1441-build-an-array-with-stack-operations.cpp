class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<int> arr;
        vector<string> ar;
        int s=0;
        if(target.size()==0) return ar;
        for(int i=1;i<=n;i++){
            if(s>=target.size()) break;
            ar.push_back("Push");
            if(target[s]!=i){
                ar.push_back("Pop");
            }
            else{
                s++;
            }
        }
        return ar;
    }
};