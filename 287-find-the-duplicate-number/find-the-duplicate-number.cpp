class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // phase 1:
        // find intersection

        int slow = nums[0];
        int fast = nums[0];

        do {

            slow = nums[slow];

            fast = nums[nums[fast]];

        } while (slow != fast);

        // phase 2:
        // find cycle entrance

        slow = nums[0];

        while (slow != fast) {

            slow = nums[slow];

            fast = nums[fast];
        }

        return slow;
    }
};