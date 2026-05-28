class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> answer(amount + 1, INT_MAX);
        answer[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (const int c : coins) {
                if (i - c >= 0 && answer[i - c] != INT_MAX) {
                    answer[i] = min(answer[i], answer[i - c] + 1);
                }
            }
        }

        return answer[amount] == INT_MAX ? -1 : answer[amount];
    }
};
