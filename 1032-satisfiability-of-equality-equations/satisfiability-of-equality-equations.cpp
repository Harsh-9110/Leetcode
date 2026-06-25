class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b)
            parent[b] = a;
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        for (int i = 0; i < 26; i++)
            parent[i] = i;
        // Process all equalities
        for (auto &eq : equations) {
            if (eq[1] == '=') {
                int u = eq[0] - 'a';
                int v = eq[3] - 'a';
                unite(u, v);
            }
        }
        // Check inequalities
        for (auto &eq : equations) {
            if (eq[1] == '!') {
                int u = eq[0] - 'a';
                int v = eq[3] - 'a';
                if (find(u) == find(v))
                    return false;
            }
        }
        return true;
    }
};