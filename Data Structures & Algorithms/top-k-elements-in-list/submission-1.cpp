class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (auto num : nums) {
            freq[num]++;
        }

        auto comp = [&](const int a, const int b) {
            return freq[a] > freq[b];
        };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);

        for (auto it : freq) {
            pq.push(it.first);

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top());
            pq.pop();
        }

        return result;
    }
};