class MinStack {
public:
    MinStack() {
        
    }
    stack<long long> s;
    long min=INT_MAX;
    void push(int value) {
        if(s.empty()){
            s.push((long long)value);
            min=(long long)value;
        }
        else{
            if(value<min){
                s.push((2*(long long)value)-min);
                min=(long long)value;
            }
            else{
                s.push((long long)value);
            }
        }
    }
    
    void pop() {
        if(s.top()>min){
            s.pop();
        }
        else{
            min=(long long)2*min-s.top();
            s.pop();
        }
    }
    
    int top() {
         if(s.top()>min){
            return s.top();
        }
        else{
            return min;
        }
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */