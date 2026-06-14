class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        unordered_map<int,int> firstPos;

        firstPos[0] = -1;

        int sum = 0;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0)
                sum -= 1;
            else
                sum += 1;

            if (firstPos.count(sum)) {

                ans = max(
                    ans,
                    i - firstPos[sum]
                );
            }
            else {

                firstPos[sum] = i;
            }
        }

        return ans;
    }
};