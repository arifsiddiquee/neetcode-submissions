class Solution {
public:

    string getHash(string& s) {
        vector<int> freq(26, 0);
        for (auto ch : s) {
            freq[ch - 'a']++;
        }

        string hash_string = "";
        for (int i = 0; i < 26; i++) {
            hash_string += to_string(freq[i]) + "."; 
        }

        return hash_string;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramsMap;

        for (auto& s : strs) {
            anagramsMap[getHash(s)].push_back(s);
        }

        vector<vector<string>> result;
        for (auto& anagrams : anagramsMap) {
            result.push_back(anagrams.second);
        }

        return result;
    }
};
