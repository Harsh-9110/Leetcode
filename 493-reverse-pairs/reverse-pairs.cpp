class Solution {
public:

    int count = 0;

    void mergeSort(
        vector<int>& nums,
        int l,
        int r) {

        if (l >= r)
            return;

        int mid = l + (r - l) / 2;

        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);

        // Count reverse pairs
        int j = mid + 1;

        for (int i = l; i <= mid; i++) {

            while (j <= r &&
                   nums[i] > 2LL * nums[j]) {
                j++;
            }

            count += j - (mid + 1);
        }

        // Normal merge
        vector<int> temp;

        int i = l;
        j = mid + 1;

        while (i <= mid && j <= r) {

            if (nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }

        while (i <= mid)
            temp.push_back(nums[i++]);

        while (j <= r)
            temp.push_back(nums[j++]);

        for (int k = l; k <= r; k++) {

            nums[k] = temp[k - l];
        }
    }
    int reversePairs(vector<int>& nums) {
        count = 0;
        mergeSort(
            nums,
            0,
            nums.size() - 1
        );
        return count;
    }
};