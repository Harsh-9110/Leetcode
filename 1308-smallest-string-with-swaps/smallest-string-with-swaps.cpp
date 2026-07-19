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

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();

        parent.resize(n);
        rank.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        for (auto &p : pairs)
            unite(p[0], p[1]);

        unordered_map<int, vector<int>> groups;

        for (int i = 0; i < n; i++)
            groups[find(i)].push_back(i);

        for (auto &g : groups) {
            vector<int> &idx = g.second;
            string chars = "";

            for (int i : idx)
                chars += s[i];

            sort(idx.begin(), idx.end());
            sort(chars.begin(), chars.end());

            for (int i = 0; i < idx.size(); i++)
                s[idx[i]] = chars[i];
        }

        return s;
    }
};