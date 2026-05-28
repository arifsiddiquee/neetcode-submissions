class Solution {
public:
    int partition(vector<int>& nums, int pivot, int l, int r) {
        int pe = nums[pivot];
        swap(nums[r], nums[pivot]);
        int j = l;
        for (int i = l; i <= r; i++) {
            if (nums[i] < pe) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        swap(nums[j], nums[r]);

        return j;
    }

    int solve(vector<int>& nums, int k, int l, int r) {
        if (l == r) {
            nums[l];
        }

        int pivot = l + (r - l) / 2;
        pivot = partition(nums, pivot, l, r);

        if (pivot == k) {
            return nums[pivot];
        } else if (pivot < k) {
            return solve(nums, k, pivot + 1, r);
        } else {
            return solve(nums, k, l, pivot - 1);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        return solve(nums, nums.size() - k, 0, nums.size() - 1);
    }
};
