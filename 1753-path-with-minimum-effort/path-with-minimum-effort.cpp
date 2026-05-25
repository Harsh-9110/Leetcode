class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<int>> dist(
            rows,
            vector<int>(cols, INT_MAX)
        );

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        dist[0][0] = 0;

        pq.push({0, 0, 0});

        vector<int> dr = {1, -1, 0, 0};
        vector<int> dc = {0, 0, 1, -1};

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int effort = curr[0];
            int r = curr[1];
            int c = curr[2];

            // reached destination
            if (r == rows - 1 &&
                c == cols - 1) {

                return effort;
            }

            for (int i = 0; i < 4; i++) {

                int nr = r + dr[i];
                int nc = c + dc[i];

                if (nr >= 0 && nr < rows &&
                    nc >= 0 && nc < cols) {

                    int edgeCost =
                        abs(
                            heights[r][c]
                            - heights[nr][nc]
                        );

                    int newEffort =
                        max(effort, edgeCost);

                    if (newEffort <
                        dist[nr][nc]) {

                        dist[nr][nc] =
                            newEffort;

                        pq.push({
                            newEffort,
                            nr,
                            nc
                        });
                    }
                }
            }
        }

        return 0;
    }
};