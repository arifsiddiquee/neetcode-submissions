class Solution {
public:
    bool isOperator(string& token) {
        return token.size() == 1 &&
            (token[0] == '+' ||
            token[0] == '-' ||
            token[0] == '*' ||
            token[0] == '/');
    }

    int operate(int a, int b, string& op) {
        switch (op[0]) {
            case '+': return a + b;
            case '-': return a - b;
            case '*': return a * b;
            case '/': return a / b;
        }
        return -1;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (auto& token : tokens) {
            if (isOperator(token)) {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();
                st.push(operate(a, b, token));
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
