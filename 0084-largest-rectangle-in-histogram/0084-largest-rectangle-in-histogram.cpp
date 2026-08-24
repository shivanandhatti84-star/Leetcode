class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxl=0;
        for(int i=0;i<heights.size();i++){
            while(!st.empty()&&heights[i]<heights[st.top()]){
                int h=heights[st.top()];
                st.pop();
                int p=st.empty()?-1:st.top(),n=i;

                maxl=max(maxl,(h*(n-p-1)));
            }
            st.push(i);
        }
        while(!st.empty()){
                int h=heights[st.top()];
                st.pop();
                int p=st.empty()?-1:st.top(),n=heights.size();

                maxl=max(maxl,(h*(n-p-1)));
           
        }
        return maxl;

    }
};