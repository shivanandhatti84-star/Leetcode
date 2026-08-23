class Solution {
public:
    vector<int> nfun(vector<int> &arr){
        vector<int> a(arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()) a[i]=arr.size();
            else a[i]=st.top();
            st.push(i);
        }
        return a;
    }
    vector<int> pfun(vector<int> &arr){
        vector<int> a(arr.size());
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty()&& arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()) a[i]=-1;
            else a[i]=st.top();
            st.push(i);
        }
        return a;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> nse=nfun(arr);
        vector<int> pse=pfun(arr);
        long long total=0,mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            long long k=nse[i]-i;
            long long l=i-pse[i];
            total=(total+(((k*l)%mod)*arr[i])%mod)%mod;
        }
        return total;
    }
};