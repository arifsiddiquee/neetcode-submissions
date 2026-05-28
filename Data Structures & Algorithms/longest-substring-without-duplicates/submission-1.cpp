class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int, int> index;
        int position = -1;
        int current_streak = 0;
        int best_streak = 0;

        for (int i = 0; i < s.size(); i++) {
            if (index.find(s[i]) != end(index)) {
                position = max(index[s[i]] + 1, position);
                current_streak = i - position + 1;
            } else {
                current_streak++;
            }
            index[s[i]] = i;
            best_streak = max(best_streak, current_streak);
        }

        return best_streak;
    }
};
