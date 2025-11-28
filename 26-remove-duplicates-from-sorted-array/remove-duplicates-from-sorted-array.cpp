class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;  // slow pointer
        
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {   // found a new unique number
                i++;
                nums[i] = nums[j];
            }
        }
        
        return i + 1;   // total unique elements
    }
};
