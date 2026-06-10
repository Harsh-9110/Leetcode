class Solution {
public:

    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int node,
             vector<vector<int>>& graph) {

        path.push_back(node);

        int target = graph.size() - 1;

        if (node == target) {
            ans.push_back(path);
        }
        else {

            for (int nei : graph[node]) {
                dfs(nei, graph);
            }
        }

        path.pop_back(); // backtrack
    }

    vector<vector<int>> allPathsSourceTarget(
        vector<vector<int>>& graph) {

        dfs(0, graph);

        return ans;
    }
};