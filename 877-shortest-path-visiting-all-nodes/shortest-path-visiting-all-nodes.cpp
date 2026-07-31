class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int finalMask = (1 << n) - 1;

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(1 << n, vector<bool>(n, false));

        for (int i = 0; i < n; i++) {
            int mask = 1 << i;
            q.push({i, mask});
            vis[mask][i] = true;
        }

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [node, mask] = q.front();
                q.pop();

                if (mask == finalMask)
                    return steps;

                for (int nei : graph[node]) {
                    int newMask = mask | (1 << nei);

                    if (!vis[newMask][nei]) {
                        vis[newMask][nei] = true;
                        q.push({nei, newMask});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};