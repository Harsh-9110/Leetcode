
class Solution {
public:
    bool isPossible(vector<int>& nums) {

        unordered_map<int, int> freq;
        unordered_map<int, int> need;

        for (int x : nums)
            freq[x]++;

        for (int x : nums) {

            if (freq[x] == 0)
                continue;

            // Extend an existing subsequence
            if (need[x] > 0) {

                need[x]--;
                need[x + 1]++;
                freq[x]--;
            }

            // Start a new subsequence
            else if (freq[x + 1] > 0 &&
                     freq[x + 2] > 0) {

                freq[x]--;
                freq[x + 1]--;
                freq[x + 2]--;

                need[x + 3]++;
            }

            else {
                return false;
            }
        }

        return true;
    }
};