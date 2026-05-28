class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) {
            return false;
        }
        
        unordered_map<char, int> freq;

        for (auto ch : s1) {
            freq[ch]++;
        }

        unordered_map<char, int> window;
        int found = 0;

        for (int i = 0; i < s1.size(); i++) {
            if (freq.find(s2[i]) != end(freq)) {
                window[s2[i]]++;
            }

            if (window[s2[i]] > 0 && window[s2[i]] == freq[s2[i]]) {
                found++;
            } else if (window[s2[i]] > 0 && window[s2[i]] - 1 == freq[s2[i]]) {
                found--;
            }
        }

        if (found == freq.size()) {
            return true;
        }

        int right = s1.size(), left = 0;

        while (right < s2.size()) {
            if (freq.find(s2[left]) != end(freq)) {
                window[s2[left]]--;
                if (window[s2[left]] == freq[s2[left]]) {
                    found++;
                } else if (window[s2[left]] + 1 == freq[s2[left]]) {
                    found--;
                }
            }
            left++;

            if (freq.find(s2[right]) != end(freq)) {
                window[s2[right]]++;
                if (window[s2[right]] == freq[s2[right]]) {
                    found++;
                } else if (window[s2[right]] - 1 == freq[s2[right]]) {
                    found--;
                }
            }
            right++;

            if (found == freq.size()) {
                return true;
            }
        }

        return false;
    }
};
