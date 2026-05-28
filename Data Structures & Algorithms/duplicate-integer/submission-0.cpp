class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> seen;
        for (auto n : nums) {
            if (!seen.insert(n).second) {
                return true;
            }
        }
        return false;
    }
};
