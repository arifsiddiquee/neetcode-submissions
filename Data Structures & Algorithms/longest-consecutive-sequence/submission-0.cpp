class Solution {
public:
    int longestConsecutive(vector<int> nums) {
        unordered_map<int, int> lows;
        unordered_map<int, int> highs;
        unordered_set<int> seen;

        for (auto n : nums) {
            if (seen.insert(n).second) {
                if (lows.find(n + 1) != end(lows)) {
                    lows[n] = lows[n + 1] + 1;
                    lows.erase(n + 1);
                    
                    int en = n + lows[n] - 1;
                    highs[en] = lows[n];

                    if (highs.find(n-1) != end(highs)) {
                        int st = n - highs[n-1];
                        lows[st] += lows[n];
                        lows.erase(n);
                        highs.erase(n-1);
                        highs[en] = lows[st];
                    }
                } else if (highs.find(n - 1) != end(highs)) {
                    int st = n - highs[n - 1];
                    lows[st]++;
                    highs.erase(n - 1);
                    highs[n] = lows[st];
                } else {
                    lows[n] = highs[n] = 1;
                }
            }
        }

        int best = 0;
        for (auto it : lows) {
            if (it.second > best) {
                best = it.second;
            }
        }

        return best;
    }
};
