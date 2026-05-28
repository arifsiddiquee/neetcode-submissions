class Solution {
  const string OPS = "+-*/";

public:
    bool isOp(string& token) {
      return token.size() == 1 && OPS.find(token) != string::npos;
    }

    int eval(int a, int b, string op) {
      switch (op[0]) {
        case '+':
          return a + b;
        case '-':
          return a - b;
        case '*':
          return a * b;
        case '/':
          return a / b;
      }
    }

    int evalRPN(vector<string>& tokens) {
      stack<int> st;

      for (auto token : tokens) {
        if (isOp(token)) {
          int b = st.top();
          st.pop();

          int a = st.top();
          st.pop();

          st.push(eval(a, b, token));
        } else {
          st.push(stoi(token));
        }
      }    

      return st.top();
    }
};