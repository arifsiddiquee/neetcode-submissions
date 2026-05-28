class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowest = INT_MAX;
        int profit = 0;
        for (auto p : prices) {
            if (p > lowest) {
                profit = max(profit, p - lowest);
            }
            lowest = min(lowest, p);
        }
        return profit;
    }
};
