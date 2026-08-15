class Solution {
public:
    void fun(vector<string> &a,string &n,string &ar,long long target,long long prev,long long val,int ind){
        if(ind==n.length()){
            if (val==target){
                a.push_back(ar);
            }
            return;
        }
        long long current=0;
        for(int j=ind;j<n.size();j++){
            if(j > ind && n[ind] == '0')  break;
            current=current*10+(n[j]-'0');
            string part = n.substr(ind, j - ind + 1);
            if(ind==0){
                ar+=part;
                fun(a,n,ar,target,current,current,j+1);
                ar.erase(ar.size()-part.size());
            }
            else{
                ar+='+'+part;
                fun(a,n,ar,target,current,current+val,j+1);
                ar.erase(ar.size()-part.size()-1);

                ar+='-'+part;
                fun(a,n,ar,target,-current,val-current,j+1);
                ar.erase(ar.size()-part.size()-1);
                
                ar += '*' + part;
                fun(a, n, ar, target,prev * current,val - prev + prev * current,j + 1);

                ar.erase(ar.size() - part.size() - 1);
    
            }
        }


    }
    vector<string> addOperators(string num, int target) {
        vector<string> a;
        string n=num;
        string ar="";
        fun(a,n,ar,target,0,0,0);
        return a;
    }
};