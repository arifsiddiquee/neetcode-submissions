class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); i++) {
          int rem = target - nums[i];
          if (seen.find(rem) != end(seen)) {
            res[0] = seen[rem];
            res[1] = i;
            break;
          }
          seen[nums[i]] = i;
        }

        return res;
    }
};
