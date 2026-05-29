class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        unordered_map<int,int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        int ans = 0;

        if (k == 0) {

            for (auto& [num, count] : freq) {

                if (count >= 2)
                    ans++;
            }
        }
        else {

            for (auto& [num, count] : freq) {

                if (freq.count(num + k))
                    ans++;
            }
        }

        return ans;
    }
};