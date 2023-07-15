class MinStack {
private:
    vector<pair<int,int>> order;
public:
    MinStack() {
    }
    
    void push(int val) {
        int mini = val;
        if(order.size() != 0){
            int lastMin = order[order.size()-1].second;
            mini = min(lastMin, mini);
        }
        order.push_back({val,mini});
    }
    
    void pop() {
        order.pop_back();
    }
    
    int top() {
        return order[order.size()-1].first;
    }
    
    int getMin() {
        return order[order.size()-1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
