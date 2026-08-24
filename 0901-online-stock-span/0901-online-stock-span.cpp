class StockSpanner {
public:
    stack<pair<int,int>> st;
    int ind=0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        while(!st.empty()&&st.top().first<=price){
            st.pop();
        }
        int ans;
        if(st.empty()) ans=ind+1;
        else ans=ind-st.top().second;
        st.push({price,ind});
        ind++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */