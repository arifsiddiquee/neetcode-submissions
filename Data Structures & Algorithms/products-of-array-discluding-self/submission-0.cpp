class Solution {
public:
    // void print(vector<int>& vi) {
    //     for (auto i : vi) {
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }

    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre(nums.size());
        pre[0] = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            pre[i + 1] = pre[i] * nums[i];
        }
        //print(pre);

        vector<int> suf(nums.size());
        suf[nums.size() - 1] = 1;
        for (int i = nums.size() - 1; i > 0; i--) {
            suf[i - 1] = suf[i] * nums[i];
        }
        //print(suf);

        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            result[i] = pre[i] * suf[i];
        }

        return result;
    }
};
