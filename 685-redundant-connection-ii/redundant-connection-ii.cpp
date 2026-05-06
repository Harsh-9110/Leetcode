class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    bool unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb)
            return false;

        parent[pa] = pb;
        return true;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        vector<int> indegree(n + 1, 0);

        vector<int> cand1, cand2;

        // detect node with 2 parents
        vector<int> directParent(n + 1, 0);

        for (auto& e : edges) {
            int u = e[0], v = e[1];

            if (directParent[v] == 0) {
                directParent[v] = u;
            } else {
                cand1 = {directParent[v], v};
                cand2 = e;

                e[1] = 0; // invalidate second edge
            }
        }

        parent.resize(n + 1);
        for (int i = 1; i <= n; i++)
            parent[i] = i;

        for (auto& e : edges) {
            int u = e[0], v = e[1];

            if (v == 0) continue;

            if (!unite(u, v)) {
                // cycle found
                if (cand1.empty())
                    return e;

                return cand1;
            }
        }

        return cand2;
    }
};