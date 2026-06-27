class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        unordered_set<string> dead(deadends.begin(), deadends.end());

        if (dead.count("0000"))
            return -1;

        queue<pair<string, int>> q;
        unordered_set<string> vis;

        q.push({"0000", 0});
        vis.insert("0000");

        while (!q.empty()) {

            auto [curr, steps] = q.front();
            q.pop();

            if (curr == target)
                return steps;

            for (int i = 0; i < 4; i++) {

                // Rotate forward
                string next = curr;
                next[i] = (curr[i] - '0' + 1) % 10 + '0';

                if (!dead.count(next) && !vis.count(next)) {
                    vis.insert(next);
                    q.push({next, steps + 1});
                }

                // Rotate backward
                next = curr;
                next[i] = (curr[i] - '0' + 9) % 10 + '0';

                if (!dead.count(next) && !vis.count(next)) {
                    vis.insert(next);
                    q.push({next, steps + 1});
                }
            }
        }

        return -1;
    }
};