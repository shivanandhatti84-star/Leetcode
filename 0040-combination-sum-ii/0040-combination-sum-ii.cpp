class Solution {
public:
    void fun(vector<int> *c, int target,int ind,vector<vector<int>> *pair,vector<int> *p){
        
        if(target==0){
            pair->push_back(*p);
            return;
        }
        for(int i=ind;i<c->size();i++){
            if(i>ind && (*c)[i]==(*c)[i-1]) continue;
            if((*c)[i]>target) break;

            p->push_back((*c)[i]);
            fun(c,target-(*c)[i],i+1,pair,p);
            p->pop_back();
        }   
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int target) {
        vector<vector<int>> pair;
        vector<int> p;
        sort(c.begin(),c.end());
        fun(&c,target,0,&pair,&p);
        return pair;
    }
};