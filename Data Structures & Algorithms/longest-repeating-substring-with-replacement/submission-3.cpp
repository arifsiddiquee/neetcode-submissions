class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int left = 0, right = 0, best = 0, max_frequency = 0;


        while (right < s.size()) {
            count[s[right]]++;

            max_frequency = max(max_frequency, count[s[right]]);

            while (left < right && (right - left + 1 - k > max_frequency)) {
                count[s[left]]--;
                left++;
            }

            best = max(best, right - left + 1);
            right++;
        }

        return best;
    }
};
