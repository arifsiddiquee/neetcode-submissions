class Solution {
public:

    unordered_map<int, string> digit_to_char_map = {
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"},
    };

    void generate(string& digits, int index, string& curr, vector<string>& result) {
        if (index >= digits.size()) {
            result.push_back(curr);
            return;
        }

        int digit = digits[index] - '0';

        for (auto ch : digit_to_char_map[digit]) {
            curr += ch;
            generate(digits, index + 1, curr, result);
            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string curr = "";

        if (!digits.empty()) {
            generate(digits, 0, curr, result);
        }

        return result;
    }
};
