class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        int n = grid.size();

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        vector<vector<int>> dist(
            n,
            vector<int>(n, INT_MAX)
        );

        dist[0][0] = grid[0][0];

        pq.push({
            grid[0][0],
            0,
            0
        });

        vector<int> dr = {1,-1,0,0};
        vector<int> dc = {0,0,1,-1};

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int time = curr[0];
            int r = curr[1];
            int c = curr[2];

            // reached destination
            if (r == n - 1 &&
                c == n - 1) {

                return time;
            }

            for (int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < n &&
                    nc >= 0 && nc < n) {

                    int newTime =
                        max(time,
                            grid[nr][nc]);

                    if (newTime <
                        dist[nr][nc]) {

                        dist[nr][nc] =
                            newTime;

                        pq.push({
                            newTime,
                            nr,
                            nc
                        });
                    }
                }
            }
        }

        return -1;
    }
};