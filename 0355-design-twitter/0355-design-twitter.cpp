class Twitter {
public:
        unordered_map<int,vector<pair<int,int>>> tweets;
        unordered_map<int,unordered_set<int>> followers;
        int time;
    Twitter() {
        time=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        for(auto at:tweets[userId]){
            pq.push(at);
            if(pq.size()>10){
                pq.pop();
            }
        }
        for(auto at:followers[userId]){
            for(auto a:tweets[at]){
                pq.push(a);
                if(pq.size()>10) pq.pop();
            }
        }
        vector<int> ab;
        while(!pq.empty()){
            ab.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ab.begin(),ab.end());
        return ab;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */