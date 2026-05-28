class MinStack {
    stack<int> values;
    stack<int> min_values;

public:
    MinStack() {
    }
    
    void push(int val) {
        int next_min = min(val, min_values.empty() ? INT_MAX : min_values.top());
        min_values.push(next_min);
        values.push(val);
    }
    
    void pop() {
        min_values.pop();
        values.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return min_values.top();
    }
};
