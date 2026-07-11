class MinStack {
public:
    stack<long long> st;
    long long mini = INT_MAX;
    MinStack() {//empty constructor
    }
    
    void push(int val) {
        long long value = val;
        if(st.empty()){
            st.push(value);
            mini = value;
        }else{
            if(mini <= value){
                st.push(value);
            }else{
                st.push(2*value - mini);
                mini = value;
            }
        }
    }
    
    void pop() {
        long long x = st.top();
        if(mini > x){
            mini = 2*mini - x;
        }
        st.pop();
    }
    
    int top() {
        long long x = st.top();
        if(mini > x) return mini;
        else return x;
    }
    
    int getMin() {
        return mini;
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