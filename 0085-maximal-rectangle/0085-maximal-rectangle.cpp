class Solution {
public:
    int fun(vector<int> &a){
        stack<int> st;
        int maxl=0;
        for(int i=0;i<a.size();i++){
            while(!st.empty()&&a[st.top()]>a[i]){
                int h=a[st.top()];
                st.pop();
                int p=(st.empty())?-1:st.top();
                int n=i;
                maxl=max(maxl,(n-p-1)*h);
            }
            st.push(i);
        }
        while(!st.empty()){
                int h=a[st.top()];
                st.pop();
                int p=(st.empty())?-1:st.top();
                int n=a.size();
                maxl=max(maxl,(n-p-1)*h);
        }
        return maxl;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<int> a(matrix[0].size(),0);
        int maxl=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]=='1') a[j]++;
                else a[j]=0;
            } 
            maxl=max(maxl,fun(a));

        }
        return maxl;
    }
};