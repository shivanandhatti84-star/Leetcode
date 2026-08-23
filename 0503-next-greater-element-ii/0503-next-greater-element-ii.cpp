class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> a(nums.size());
        stack<int> st;
        for(int i=2*(nums.size())-1;i>=0;i--){
            int ind=i%nums.size();
            while(!st.empty() && st.top()<=nums[ind]){
                st.pop();
            }
            if(st.empty()) a[ind]=-1;
            else a[ind]=st.top();
            st.push(nums[ind]);
        }
        return a;
    }
};