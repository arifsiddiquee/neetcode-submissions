class Solution {
public:
  string minWindow(string s, string t) {
    vector<int> target(52, 0);
    vector<int> source(52, 0);

    for (int i = 0; i < t.size(); i++) {
      target[t[i] >= 'a' ? (t[i] - 'a' + 26) : (t[i] - 'A')]++;
      source[s[i] >= 'a' ? (s[i] - 'a' + 26) : (s[i] - 'A')]++;
    }

    int m = 0;
    for (int i = 0; i < 52; i++) {
      if (target[i] > 0 && target[i] <= source[i]) {
        m += target[i];
      }
    }

    int left = 0, right = t.size(), best = INT_MAX, best_start = -1;
    while (right < s.size()) {
      if (m == t.size()) {
        if (best > (right - left)) {
          best = right - left;
          best_start = left;
        }
      }
      int idxRight = s[right] >= 'a' ? (s[right] - 'a' + 26) : (s[right] - 'A');
      if (target[idxRight] > 0) {
        source[idxRight]++;
        if (source[idxRight] == target[idxRight]) {
          m++;
        }
      }
      right++;

      while (left < right) {
        int idxLeft = s[left] >= 'a' ? (s[left] - 'a' + 26) : (s[left] - 'A');
        if (target[idxLeft] > 0) {
          if (source[idxLeft] == target[idxLeft]) {
            break;
          }
          source[idxLeft]--;
        }
        left++;
      }
    }

    if (m == t.size()) {
      if (best > (right - left)) {
        best = right - left;
        best_start = left;
      }
    }

    return best_start == -1 ? "" : s.substr(best_start, best);
  }
};