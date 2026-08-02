class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int, int>>> graph(n);

        for (auto &e : edges) {
            graph[e[0]].push_back({e[1], e[2]});
            graph[e[1]].push_back({e[0], e[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto &[v, cnt] : graph[u]) {
                long long nd = d + cnt + 1;

                if (nd < dist[v]) {
                    dist[v] = nd;
                    pq.push({nd, v});
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
            if (dist[i] <= maxMoves)
                ans++;

        for (auto &e : edges) {
            long long a = dist[e[0]] > maxMoves ? 0 : maxMoves - dist[e[0]];
            long long b = dist[e[1]] > maxMoves ? 0 : maxMoves - dist[e[1]];

            ans += min((long long)e[2], a + b);
        }

        return ans;
    }
};