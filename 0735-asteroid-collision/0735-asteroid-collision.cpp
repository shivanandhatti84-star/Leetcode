class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        if(a.size()==1||a.size()==0) return a;
        vector<int> ark;
        for(int i=0;i<a.size();i++){
            if(a[i]>0){
                ark.push_back(a[i]);
            }
            else{
                while(!ark.empty()&&ark.back()>0&&ark.back()<abs(a[i])){
                    ark.pop_back();
                }
                if(!ark.empty()&&ark.back()==abs(a[i])){
                    ark.pop_back();
                }
                else if((ark.empty()&&a[i]<0)||(ark.back()<0)){
                    ark.push_back(a[i]);
                } 
            }
        }
        return ark;
    }
};