class Solution {
public:
    string getHash(string s) {
      vector<int> f(26, 0);
      for (auto ch : s) {
        f[ch - 'a']++;
      }
      string hash = "";
      for (int i = 0; i < 26; i++) {
        if (f[i] > 0) {
          hash += ('a' + i);
          hash += to_string(f[i]);
          hash += '#';
        }
      }

      return hash;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;

        for (auto s : strs) {
          mp[getHash(s)].push_back(s);
        }

        vector<vector<string>> result;
        for (auto it : mp) {
          result.push_back(it.second);
        }

        return result;
    }
};
