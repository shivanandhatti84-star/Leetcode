class MedianFinder {
public:
priority_queue<int> maxl;
priority_queue<int,vector<int>,greater<int>> minl;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxl.empty()||maxl.top()>=num){
            maxl.push(num);
        }
        else{
            minl.push(num);
        }

        if(maxl.size()>minl.size()+1){
            minl.push(maxl.top());
            maxl.pop();
        }
        else if(minl.size()>maxl.size()){
            maxl.push(minl.top());
            minl.pop();
        }
    }
    
    double findMedian() {
        if(maxl.size()>minl.size()){
            return maxl.top();
        }
        return (maxl.top()+minl.top())/2.0; 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */