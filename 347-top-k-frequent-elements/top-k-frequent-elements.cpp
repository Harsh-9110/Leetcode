class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> freq;

        // count frequency
        for (int num : nums) {
            freq[num]++;
        }

        // bucket[i] = numbers appearing i times
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& [num, f] : freq) {
            bucket[f].push_back(num);
        }

        vector<int> ans;

        // traverse from highest freq
        for (int i = bucket.size() - 1; i >= 0; i--) {

            for (int num : bucket[i]) {
                ans.push_back(num);

                if (ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};