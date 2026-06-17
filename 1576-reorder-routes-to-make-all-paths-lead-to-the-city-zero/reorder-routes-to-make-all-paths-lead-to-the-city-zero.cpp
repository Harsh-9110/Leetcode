class Solution {
public:
    int dfs(int node,
            int parent,
            vector<vector<pair<int,int>>>& adj) {
        int changes = 0;
        for (auto &[next, cost] : adj[node]) {
            if (next == parent)
                continue;
            changes += cost;
            changes += dfs(
                next,
                node,
                adj
            );
        }
        return changes;
    }
    int minReorder(int n,
                   vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : connections) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back({v, 1});
            adj[v].push_back({u, 0});
        }
        return dfs(0, -1, adj);
    }
};