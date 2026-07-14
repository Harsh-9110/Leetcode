class NumArray {
public:
    vector<int> bit;
    vector<int> nums;
    int n;

    NumArray(vector<int>& arr) {
        n = arr.size();
        bit.assign(n + 1, 0);
        nums = arr;

        for (int i = 0; i < n; i++)
            add(i + 1, arr[i]);
    }

    void add(int index, int val) {
        while (index <= n) {
            bit[index] += val;
            index += index & (-index);
        }
    }

    int prefixSum(int index) {
        int sum = 0;
        while (index > 0) {
            sum += bit[index];
            index -= index & (-index);
        }
        return sum;
    }

    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        add(index + 1, diff);
    }

    int sumRange(int left, int right) {
        return prefixSum(right + 1) - prefixSum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
 