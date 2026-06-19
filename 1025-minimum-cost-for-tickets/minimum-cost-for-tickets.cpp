class Solution {
public:

    vector<int> dp;

    int solve(int i,
              vector<int>& days,
              vector<int>& costs) {

        if (i >= days.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        int oneDay =
            costs[0] +
            solve(i + 1, days, costs);

        int j = i;

        while (j < days.size() &&
               days[j] < days[i] + 7)
            j++;

        int sevenDay =
            costs[1] +
            solve(j, days, costs);

        j = i;

        while (j < days.size() &&
               days[j] < days[i] + 30)
            j++;

        int thirtyDay =
            costs[2] +
            solve(j, days, costs);

        return dp[i] =
            min({oneDay,
                 sevenDay,
                 thirtyDay});
    }

    int mincostTickets(
        vector<int>& days,
        vector<int>& costs) {

        dp.assign(days.size(), -1);

        return solve(0, days, costs);
    }
};