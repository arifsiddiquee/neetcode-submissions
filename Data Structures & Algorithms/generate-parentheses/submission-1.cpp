class Solution {
public:

    void generate(int open, int closed, string& curr, vector<string>& result) {
        if (open == closed && open == 0) {
            result.push_back(curr);
            return;
        }

        if (open == 0) {
            curr += ")";
            generate(open, closed - 1, curr, result);
            curr.pop_back();
            return;
        }

        if (open > 0) {
            curr += "(";
            generate(open - 1, closed, curr, result);
            curr.pop_back();
        }

        if (closed > open) {
            curr += ")";
            generate(open, closed - 1, curr, result);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string curr = "";
        vector<string> result;
        generate(n, n, curr, result);
        return result;
    }
};
