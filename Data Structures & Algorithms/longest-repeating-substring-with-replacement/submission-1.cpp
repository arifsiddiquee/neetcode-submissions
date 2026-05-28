class Solution {
public:
    int replacementRequired(vector<int>& freq, int total) {
        int mx = *max_element(freq.begin(), freq.end());
        return total - mx;
    }

    int characterReplacement(string s, int k) {
        int left = 0, right = 0;
        vector<int> freq(26, 0);
        int best = 0;

        while (right < s.size()) {
            freq[s[right] - 'A']++;
            while (replacementRequired(freq, right - left + 1) > k && left < right) {
                freq[s[left] - 'A']--;
                left++;
            }
            right++;
            best = max(best, right - left);
        }

        return best;
    }
};
