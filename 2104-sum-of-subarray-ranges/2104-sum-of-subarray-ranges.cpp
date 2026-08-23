class Solution {
public:
    vector<int> nfu(vector<int> nums){
        stack<int> st;
        vector<int> a(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]<=nums[i]){
                st.pop();
            }
            if(st.empty()) a[i]=nums.size();
            else a[i]=st.top();
            st.push(i);
        }
        return a;
    }

    vector<int> pfu(vector<int> nums){
        stack<int> st;
        vector<int> a(nums.size());
        for(int i=0;i<nums.size();i++){
            while(!st.empty()&&nums[st.top()]<nums[i]){
                st.pop();
            }
            if(st.empty()) a[i]=-1;
            else a[i]=st.top();
            st.push(i);
        }
        return a;
    }   
    vector<int> pfun(vector<int> nums){
        stack<int> st;
        vector<int> a(nums.size());
        for(int i=0;i<nums.size();i++){
            while(!st.empty()&&nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.empty()) a[i]=-1;
            else a[i]=st.top();
            st.push(i);
        }
        return a;
    }

    vector<int> nfun(vector<int> &nums){
        stack<int> st;
        vector<int> a(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()) a[i]=nums.size();
            else a[i]=st.top();
            st.push(i);
        }
        return a;
    }
    long long subArrayRanges(vector<int>& nums) {
        vector<int> nse=nfun(nums);
        vector<int> pse=pfun(nums);
        vector<int> pge=pfu(nums);
        vector<int> nge=nfu(nums);

        long long sum=0,mod=1e9+7;
        for(int i=0;i<nums.size();i++){
            long long k=nse[i]-i;
            long long l=i-pse[i];
            long long min=k*l*nums[i];
            k=nge[i]-i;
            l=i-pge[i];
            long long max=k*l*nums[i];
            sum+=(max-min);
        }
        return sum;
    }
};