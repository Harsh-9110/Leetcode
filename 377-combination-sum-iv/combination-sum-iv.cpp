class Solution {
public:
    int combinationSum4(
        vector<int>& nums,
        int target) {

        vector<unsigned long long>
            dp(target + 1, 0);

        dp[0] = 1;

        for (int t = 1;
             t <= target;
             t++) {

            for (int num : nums) {

                if (num <= t) {

                    dp[t] +=
                        dp[t - num];
                }
            }
        }

        return dp[target];
    }
};