class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> rev(n);
        vector<int> outdegree(n, 0);

        // build reverse graph
        for (int u = 0; u < n; u++) {
            outdegree[u] = graph[u].size();

            for (int v : graph[u]) {
                rev[v].push_back(u);
            }
        }

        queue<int> q;

        // terminal nodes
        for (int i = 0; i < n; i++) {
            if (outdegree[i] == 0)
                q.push(i);
        }

        vector<int> safe;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            safe.push_back(node);

            for (int parent : rev[node]) {
                outdegree[parent]--;

                if (outdegree[parent] == 0) {
                    q.push(parent);
                }
            }
        }

        sort(safe.begin(), safe.end());
        return safe;
    }
};