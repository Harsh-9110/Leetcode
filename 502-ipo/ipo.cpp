class Solution {
public:
    int findMaximizedCapital(int k, int w,
                             vector<int>& profits,
                             vector<int>& capital) {

        int n = profits.size();

        // min heap -> {capital needed, profit}
        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> minCap;

        for (int i = 0; i < n; i++) {
            minCap.push({capital[i], profits[i]});
        }

        // max heap -> profits
        priority_queue<int> maxProfit;

        for (int i = 0; i < k; i++) {

            // add all affordable projects
            while (!minCap.empty() &&
                   minCap.top().first <= w) {

                maxProfit.push(minCap.top().second);
                minCap.pop();
            }

            // no available project
            if (maxProfit.empty())
                break;

            // do most profitable project
            w += maxProfit.top();
            maxProfit.pop();
        }

        return w;
    }
};