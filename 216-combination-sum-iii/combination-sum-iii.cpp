class Solution {
public:

    vector<vector<int>> ans;
    vector<int> curr;

    void dfs(int start,
             int k,
             int target,
             int sum) {

        if (curr.size() == k) {

            if (sum == target)
                ans.push_back(curr);

            return;
        }

        if (sum > target)
            return;

        for (int i = start; i <= 9; i++) {

            curr.push_back(i);

            dfs(i + 1,
                k,
                target,
                sum + i);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(
        int k,
        int n) {

        dfs(1, k, n, 0);

        return ans;
    }
};