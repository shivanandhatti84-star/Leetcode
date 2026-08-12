class Solution {
public:
    void fun(vector<int> *c,int target,int ind,vector<vector<int>> *pair,vector<int> *p){
        if(c->size()==ind||target==0){
            if(target==0){
                pair->push_back(*p);
            }
            return;
        }
        if((*c)[ind]<=target){
            p->push_back((*c)[ind]);
            fun(c,target-(*c)[ind],ind,pair,p);
            p->pop_back();
        }
        fun(c,target,ind+1,pair,p);

    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>> pair;
        vector<int> p;
        fun(&c,target,0,&pair,&p);
        return pair;
    }
};