class Solution {
public:
    vector<int> parent, rank;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py)
            return;

        if (rank[px] < rank[py])
            swap(px, py);

        parent[py] = px;

        if (rank[px] == rank[py])
            rank[px]++;
    }

    bool similar(string &a, string &b) {
        int diff = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                diff++;

            if (diff > 2)
                return false;
        }

        return diff == 0 || diff == 2;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();

        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (similar(strs[i], strs[j]))
                    unite(i, j);
            }
        }

        unordered_set<int> groups;

        for (int i = 0; i < n; i++)
            groups.insert(find(i));

        return groups.size();
    }
};