class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mapl;
        for(int num:nums){
            mapl[num]++;
        }
        priority_queue<pair<int,int>> pq;
        for(int num:nums){
            if(mapl.find(num)!=mapl.end()){
                pq.push({mapl[num],num});
                mapl.erase(num);
            }
        }
        vector<int> a;
        while(k-- && !pq.empty()){
            auto[x,y]=pq.top();
            pq.pop();
            a.push_back(y);
        }
        return a;
    }
    
};