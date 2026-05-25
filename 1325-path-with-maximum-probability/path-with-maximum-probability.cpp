class Solution {
public:
    double maxProbability(int n,
                          vector<vector<int>>& edges,
                          vector<double>& succProb,
                          int start,
                          int end) {

        vector<vector<pair<int,double>>> adj(n);

        // build graph
        for (int i = 0;
             i < edges.size();
             i++) {

            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            adj[u].push_back({v, prob});
            adj[v].push_back({u, prob});
        }

        // max heap
        priority_queue<
            pair<double,int>
        > pq;

        vector<double> best(n, 0.0);

        best[start] = 1.0;

        pq.push({1.0, start});

        while (!pq.empty()) {

            auto [prob, node] =
                pq.top();

            pq.pop();

            // reached destination
            if (node == end)
                return prob;

            // skip outdated entry
            if (prob < best[node])
                continue;

            for (auto& [nei, edgeProb]
                 : adj[node]) {

                double newProb =
                    prob * edgeProb;

                if (newProb >
                    best[nei]) {

                    best[nei] =
                        newProb;

                    pq.push({
                        newProb,
                        nei
                    });
                }
            }
        }

        return 0.0;
    }
};