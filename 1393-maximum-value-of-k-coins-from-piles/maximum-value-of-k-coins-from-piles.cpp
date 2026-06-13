class Solution {
public:

    vector<vector<int>> memo;

    int solve(int i,
              int k,
              vector<vector<int>>& piles) {

        if (k == 0)
            return 0;

        if (i == piles.size())
            return 0;

        if (memo[i][k] != -1)
            return memo[i][k];

        int ans = solve(i + 1, k, piles);

        int curr = 0;

        for (int take = 1;
             take <= min((int)piles[i].size(), k);
             take++) {

            curr += piles[i][take - 1];

            ans = max(
                ans,
                curr +
                solve(i + 1,
                      k - take,
                      piles)
            );
        }

        return memo[i][k] = ans;
    }

    int maxValueOfCoins(
        vector<vector<int>>& piles,
        int k) {

        int n = piles.size();

        memo.assign(
            n,
            vector<int>(k + 1, -1)
        );

        return solve(0, k, piles);
    }
};