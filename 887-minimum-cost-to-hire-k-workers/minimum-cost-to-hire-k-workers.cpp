class Solution {
public:
    double mincostToHireWorkers(
        vector<int>& quality,
        vector<int>& wage,
        int k) {

        int n = quality.size();

        vector<pair<double,int>> workers;

        for (int i = 0; i < n; i++) {

            double ratio =
                (double)wage[i] / quality[i];

            workers.push_back(
                {ratio, quality[i]}
            );
        }

        sort(workers.begin(),
             workers.end());

        priority_queue<int> pq;

        long long sumQ = 0;

        double ans = 1e18;

        for (auto &[ratio, q] : workers) {

            pq.push(q);
            sumQ += q;

            if (pq.size() > k) {

                sumQ -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {

                ans = min(
                    ans,
                    ratio * sumQ
                );
            }
        }

        return ans;
    }
};