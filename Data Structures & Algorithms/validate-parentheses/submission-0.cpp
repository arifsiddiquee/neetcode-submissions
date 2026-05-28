class Solution {
public:
    bool isOpen(char ch) {
      return ch == '(' || ch == '[' || ch == '{';
    }

    bool matches(char open, char close) {
      switch (open) {
        case '(':
          return close == ')';
        case '[':
          return close == ']';
        case '{':
          return close == '}';
      }

      return false;
    }

    bool isValid(string s) {
      stack<char> st;

      for (auto ch : s) {
        if (isOpen(ch)) {
          st.push(ch);
        } else {
          if (st.empty() || !matches(st.top(), ch)) {
            return false;
          }
          st.pop();
        }
      }

      return st.empty();
    }
};