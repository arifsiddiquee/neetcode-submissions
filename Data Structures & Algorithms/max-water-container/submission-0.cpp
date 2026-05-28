class Solution {
public:
    int maxArea(vector<int>& heights) {
        int area = 0;

        for (int i = 0, j = heights.size() - 1; i < j; ) {
            area = max(area, min(heights[i], heights[j]) * (j - i));
            if (heights[i] < heights[j]) {
                i++;
            } else {
                j--;
            }
        }

        return area;
    }
};
