class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<pair<int, int>>> sums;

        set<int> seen;
        for (int i = 0; i < n; i++) {
            if (seen.insert(nums[i]).second) {
                for (int j = i + 1; j < n; j++) {
                    int target = -(nums[i] + nums[j]);
                    sums[target].push_back({i, j});
                }
            }
        }

        set<vector<int>> result;
        for (int k = 0; k < n; k++) {
            if (sums.find(nums[k]) != end(sums)) {                    
                for (auto& t : sums[nums[k]]) {
                    if (t.second < k) {
                        result.insert({nums[t.first], nums[t.second], nums[k]});
                    }
                }
            }
        }

        return vector<vector<int>>(result.begin(), result.end());
    }
};
