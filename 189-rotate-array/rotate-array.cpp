class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // handle cases where k > n

        // reverse whole array
        reverse(nums.begin(), nums.end());

        // reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // reverse last n-k elements
        reverse(nums.begin() + k, nums.end());
    }
};