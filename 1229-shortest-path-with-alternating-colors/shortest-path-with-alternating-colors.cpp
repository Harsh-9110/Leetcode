class Solution {
public:
    vector<int> shortestAlternatingPaths(
        int n,
        vector<vector<int>>& redEdges,
        vector<vector<int>>& blueEdges) {

        vector<vector<int>> red(n), blue(n);

        for (auto &e : redEdges)
            red[e[0]].push_back(e[1]);

        for (auto &e : blueEdges)
            blue[e[0]].push_back(e[1]);

        vector<int> ans(n, -1);

        vector<vector<bool>> vis(n,
                                 vector<bool>(2, false));

        queue<pair<int,int>> q;

        q.push({0,0}); // last color = red
        q.push({0,1}); // last color = blue

        vis[0][0] = true;
        vis[0][1] = true;

        int dist = 0;

        while (!q.empty()) {

            int sz = q.size();

            for (int i = 0; i < sz; i++) {

                auto [node,color] = q.front();
                q.pop();

                if (ans[node] == -1)
                    ans[node] = dist;

                if (color == 0) {

                    // Need blue next

                    for (int nei : blue[node]) {

                        if (!vis[nei][1]) {

                            vis[nei][1] = true;
                            q.push({nei,1});
                        }
                    }
                }
                else {

                    // Need red next

                    for (int nei : red[node]) {

                        if (!vis[nei][0]) {

                            vis[nei][0] = true;
                            q.push({nei,0});
                        }
                    }
                }
            }

            dist++;
        }

        return ans;
    }
};