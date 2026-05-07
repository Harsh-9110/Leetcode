class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, vector<int>& nums, vector<int>& temp) {
        // store current subset
        ans.push_back(temp);

        for (int i = idx; i < nums.size(); i++) {
            temp.push_back(nums[i]);      // take element
            solve(i + 1, nums, temp);     // recurse
            temp.pop_back();              // backtrack
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(0, nums, temp);
        return ans;
    }
};