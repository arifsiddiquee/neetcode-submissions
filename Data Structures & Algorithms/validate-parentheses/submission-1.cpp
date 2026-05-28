
class Solution {
public:
    char getMatching(char ch) {
        switch (ch) {
            case ')': return '(';
            case '}': return '{';
            case ']': return '[';
        }
        return '#';
    }

    bool isValid(string s) {
        stack<char> st;
        for (auto ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                auto opening = getMatching(ch);
                if (st.empty() || st.top() != opening) {
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
