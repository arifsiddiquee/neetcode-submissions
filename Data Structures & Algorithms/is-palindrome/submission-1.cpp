class Solution {
public:
    string sanitize(string& input_str) {
        string result = "";
        for (auto ch : input_str) {
            if (isalnum(ch)) {
                result += isdigit(ch) ? ch : tolower(ch);
            }
        }

        return result;
    }


    bool isPalindrome(string input_str) {
        string s = sanitize(input_str);

        for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
            if (s[i] != s[j]) return false;
        }

        return true;
    }
};
