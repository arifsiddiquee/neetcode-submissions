class Solution {
public:
    bool isPalindrome(string s) {
        string ss = "";
        for (auto ch : s) {
            if (isalnum(ch)) {
                ss += tolower(ch);
            }            
        }
        for (int i = 0, j = ss.size() - 1; i < j; i++, j--) {
            if (ss[i] != ss[j]) {
                return false;
            }
        }
        return true;
    }
};
