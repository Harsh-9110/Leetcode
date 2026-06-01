class Solution {
public:
    unordered_set<string> vis;
    string ans;

    void dfs(string node, int k) {
        for (int x = 0; x < k; x++) {
            string edge = node + char('0' + x);

            if (!vis.count(edge)) {
                vis.insert(edge);
                dfs(edge.substr(1), k);
                ans.push_back('0' + x);
            }
        }
    }

    string crackSafe(int n, int k) {
        string start(n - 1, '0');

        dfs(start, k);

        return ans + start;
    }
};