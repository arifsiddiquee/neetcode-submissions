class Solution {
public:
    bool isPossible(vector<int>& piles, int k, long long h) {
        long long required = 0;
        for (auto p : piles) {
            required += (p + k - 1 ) / k;
            if (required > h) return false;
        }

        return required <= h;
    }

    int minEatingSpeed(vector<int>& piles, int _h) {
        long long h = _h;

        long long low = 1, high = 1e9;
        long long found = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(piles, mid, h)) {
                found = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return found;
    }
};
