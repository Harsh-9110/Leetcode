class Solution {
public:

    bool canSplit(vector<int>& nums,
                  int k,
                  long long maxSum) {

        int parts = 1;

        long long currSum = 0;

        for (int num : nums) {

            // start new subarray
            if (currSum + num > maxSum) {

                parts++;

                currSum = 0;
            }

            currSum += num;
        }

        return parts <= k;
    }

    int splitArray(vector<int>& nums,
                   int k) {

        long long left =
            *max_element(nums.begin(),
                         nums.end());

        long long right =
            accumulate(nums.begin(),
                       nums.end(),
                       0LL);

        long long ans = right;

        while (left <= right) {

            long long mid =
                left + (right - left) / 2;

            if (canSplit(nums, k, mid)) {

                ans = mid;

                right = mid - 1;
            }
            else {

                left = mid + 1;
            }
        }

        return ans;
    }
};