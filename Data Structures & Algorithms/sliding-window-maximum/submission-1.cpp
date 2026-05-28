class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> window;

        for (int i = 0; i < k; i++) {
            window.insert(nums[i]);
        }

        int left = 0, right = k - 1;
        vector<int> result;

        do {
            result.push_back(*window.rbegin());
            window.erase(window.find(nums[left++]));
            right++;
            if (right < nums.size()) {
                window.insert(nums[right]);
            }
        } while (right < nums.size());

        return result;
    }
};
