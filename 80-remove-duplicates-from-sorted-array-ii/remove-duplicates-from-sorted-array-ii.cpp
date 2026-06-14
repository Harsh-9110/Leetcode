class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        if (n <= 2)
            return n;

        int write = 2;

        for (int i = 2; i < n; i++) {

            if (nums[i] != nums[write - 2]) {

                nums[write] = nums[i];
                write++;
            }
        }

        return write;
    }
};