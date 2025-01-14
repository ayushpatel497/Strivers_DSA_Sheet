class MinStack {
public:
    stack<long long> st;
    long long mini;
    
    MinStack() {
        // Q. Min Stack
        mini = INT_MAX;
    }
    
    void push(int value) {
        long long val = 1LL * value;
        if (st.empty()) {
            mini = val;
            st.push(val);
        } 
        else {
            if (val < mini) {
                st.push(2 * val - mini);
                mini = val;
            } 
            else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if (st.empty()) return;
        long long element = st.top();
        st.pop();

        if (element < mini) {
            mini = 2 * mini - element;
        }
    }
    
    int top() {
        if (st.empty()) 
            return -1;
        long long element = st.top();
        if (element < mini) 
            return mini;
        return element;
    }
    
    int getMin() {
        return mini;
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