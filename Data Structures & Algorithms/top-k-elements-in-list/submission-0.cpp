class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      map<int, int> mp;

      auto comp = [&](const int a, const int b) {
        return mp[a] > mp[b];
      };
      priority_queue<int, vector<int>, decltype(comp)> pq(comp);

      for (auto n : nums) {
        mp[n]++;
      }

      for (auto it : mp) {
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
