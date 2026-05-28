class UnionFind {
    vector<int> parent;
    vector<int> rank;
    int maxRank;

    public:

    UnionFind(int n) {
        parent.assign(n, -1);
        rank.assign(n, 1);
        maxRank = 1;
    }

    int find(int u) {
        if (parent[u] == -1) {
            return parent[u] = u;
        }
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }

    void connect(int u, int v) {
        u = find(u);
        v = find(v);

        if (u != v) {
            parent[v] = u;
            rank[u] += rank[v];
            maxRank = max(maxRank, rank[u]);
        }
    }

    int getMaxRank() {
        return maxRank;
    }
};


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_map<int, int> seen;
        UnionFind *uf = new UnionFind(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            if (seen.find(nums[i]) != end(seen)) {
                continue;
            }
            seen[nums[i]] = i;

            if (seen.find(nums[i] - 1) != end(seen)) {
                uf->connect(i, seen[nums[i] - 1]);
            }
            if (seen.find(nums[i] + 1) != end(seen)) {
                uf->connect(i, seen[nums[i] + 1]);
            }
        }

        return uf->getMaxRank();
    }
};
