class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<bool> seen(128, false);
        int left = 0, right = 0, best = 0;

        while (right < s.size()) {
          while (seen[s[right]] && left < right) {
            seen[s[left]] = false;
            left++;
          }
          seen[s[right]] = true;
          right++;
          best = max(best, right - left);
        }

        return best;
    }
};