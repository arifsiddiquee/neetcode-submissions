class MinStack {
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {        
    }
    
    void push(int val) {
        minSt.push(st.empty() || minSt.top() > val ? val : minSt.top());
        st.push(val);
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
