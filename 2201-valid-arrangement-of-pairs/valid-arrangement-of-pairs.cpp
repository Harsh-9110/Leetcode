class Solution {
public:

    unordered_map<int, vector<int>> graph;
    vector<int> path;

    void dfs(int node) {

        auto &adj = graph[node];

        while (!adj.empty()) {

            int next = adj.back();
            adj.pop_back();

            dfs(next);
        }

        path.push_back(node);
    }

    vector<vector<int>> validArrangement(
        vector<vector<int>>& pairs) {

        unordered_map<int,int> indegree;
        unordered_map<int,int> outdegree;

        for (auto &p : pairs) {

            int u = p[0];
            int v = p[1];

            graph[u].push_back(v);

            outdegree[u]++;
            indegree[v]++;
        }

        int start = pairs[0][0];

        for (auto &[node, out] : outdegree) {

            if (out - indegree[node] == 1) {

                start = node;
                break;
            }
        }

        dfs(start);

        reverse(path.begin(), path.end());

        vector<vector<int>> ans;

        for (int i = 0;
             i + 1 < path.size();
             i++) {

            ans.push_back(
                {path[i], path[i + 1]}
            );
        }

        return ans;
    }
};