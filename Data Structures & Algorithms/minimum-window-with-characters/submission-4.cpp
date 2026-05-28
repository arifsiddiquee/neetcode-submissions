class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) {
            return "";
        }
        
        unordered_map<char, int> freq;

        for (auto ch : t) {
            freq[ch]++;
        }

        unordered_map<char, int> window;
        int matched = 0;
        int right = 0, left = 0;
        int start = -1, best = INT_MAX;

        do {
            if (freq.find(s[right]) != end(freq)) {
                window[s[right]]++;
                if (window[s[right]] == freq[s[right]]) {
                    matched++;
                }
            }
            right++;

            if (matched == freq.size()) {
                while (left < right && matched == freq.size()) {
                    if (right - left < best) {
                        best = right - left;
                        start = left;
                    }                 
                    if (freq.find(s[left]) != end(freq)) {   
                        window[s[left]]--;
                        if (window[s[left]] == freq[s[left]] - 1) {
                            matched--;
                        }
                    }

                    left++;
                }
            }
        } while (right < s.size());

        return start != -1 ? s.substr(start, best) : "";       
    }
};
