class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int curr = 1, maxi = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                curr++;
            } else {
                curr = 1;
            }
            maxi = max(maxi, curr);
        }

        return maxi;
    }
};