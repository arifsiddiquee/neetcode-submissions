class Solution {
public:

    bool matches(vector<int>& target, vector<int>& curr) {
      for (int i = 0; i < 26; i++) {
        if (target[i] != curr[i]) {
          return false;
        }
      }
      return true;
    }

    bool checkInclusion(string s1, string s2) {
      if (s1.size() > s2.size()) return false;

      vector<int> target(26, 0);
      for (auto ch : s1) {
        target[ch - 'a']++;
      }

      vector<int> curr(26, 0);
      for (int i = 0; i < s1.size(); i++) {
        curr[s2[i] - 'a']++;
      }

      int i = 0;
      while (true) {
        if (matches(target, curr)) {
          return true;
        }

        if (i + s1.size() >= s2.size()) break;

        curr[s2[i] - 'a']--;
        curr[s2[i + s1.size()] - 'a']++;
        i++;
      }

      return false;
    }
};