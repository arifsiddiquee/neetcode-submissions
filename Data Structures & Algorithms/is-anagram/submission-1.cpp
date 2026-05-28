class Solution {
public:
    const int CHARSET_SIZE = 26;

    vector<int> countCharacterFrequency(string& s) {
        vector<int> freq(CHARSET_SIZE, 0);

        for (auto ch : s) {
            freq[ch - 'a']++;
        }

        return freq;
    }

    bool isAnagram(string s, string t) {
        auto sFreq = countCharacterFrequency(s);
        auto tFreq = countCharacterFrequency(t);

        for (int i = 0; i < CHARSET_SIZE; i++) {
            if (sFreq[i] != tFreq[i]) {
                return false;
            }
        }

        return true;
    }
};
