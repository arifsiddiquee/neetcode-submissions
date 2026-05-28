class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> total(amount + 1, 0);
        total[0] = 1;

        for (const int c : coins) {
          for (int i = 0; i <= amount; i++) {
            if (i - c >= 0) {
              total[i] += total[i - c];
            }
          }
        }

        return total[amount];
    }
};
