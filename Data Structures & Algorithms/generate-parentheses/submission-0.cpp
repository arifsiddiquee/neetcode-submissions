class Solution {
public:

  void solve(int open, int close, string& curr, vector<string>& result) {
    if (open == close && open == 0) {
      result.push_back(curr);
    }
    if (open > 0) {
      curr += '(';
      solve(open - 1, close, curr, result);
      curr.pop_back();
    }
    if (close > open && close > 0) {
      curr += ')';
      solve(open, close - 1, curr, result);
      curr.pop_back();
    }
  }

  vector<string> generateParenthesis(int n) {
    vector<string> result;
    string curr = "";
    solve(n, n, curr, result);        
    return result;
  }
};
