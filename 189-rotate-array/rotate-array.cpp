class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 0) return;

        k %= n;
        if(k == 0) return;

        // Step 1: reverse full array
        reverse(nums.begin(), nums.end());

        // Step 2: reverse first k elements
        reverse(nums.begin(), nums.begin() + k);

        // Step 3: reverse remaining n-k elements
        reverse(nums.begin() + k, nums.end());
    }
};
