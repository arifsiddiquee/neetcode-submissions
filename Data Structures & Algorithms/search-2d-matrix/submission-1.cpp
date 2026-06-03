class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size();
        int COLS = ROWS > 0 ? matrix.front().size() : 0;
        int low = 0, high = ROWS * COLS - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int r = mid / COLS;
            int c = mid % COLS;

            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return false;
    }
};
