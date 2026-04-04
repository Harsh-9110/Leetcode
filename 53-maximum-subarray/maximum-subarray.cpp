class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0, maxi = INT_MIN;
        
        for (int x : nums) {
            curr += x;
            maxi = max(maxi, curr);
            if (curr < 0) curr = 0;
        }
        
        return maxi;
    }
};