class NumArray {
public:
    vector<int> seg;
    vector<int> nums;
    int n;

    NumArray(vector<int>& arr) {
        nums = arr;
        n = nums.size();

        seg.resize(4 * n);

        build(0, 0, n - 1);
    }

    void build(int idx, int low, int high) {

        if (low == high) {
            seg[idx] = nums[low];
            return;
        }

        int mid = (low + high) / 2;

        build(2 * idx + 1, low, mid);
        build(2 * idx + 2, mid + 1, high);

        seg[idx] =
            seg[2 * idx + 1] +
            seg[2 * idx + 2];
    }

    void updateHelper(
        int idx,
        int low,
        int high,
        int pos,
        int val) {

        if (low == high) {
            seg[idx] = val;
            return;
        }

        int mid = (low + high) / 2;

        if (pos <= mid)
            updateHelper(
                2 * idx + 1,
                low,
                mid,
                pos,
                val);
        else
            updateHelper(
                2 * idx + 2,
                mid + 1,
                high,
                pos,
                val);

        seg[idx] =
            seg[2 * idx + 1] +
            seg[2 * idx + 2];
    }

    void update(int index, int val) {

        updateHelper(
            0,
            0,
            n - 1,
            index,
            val);
    }

    int query(
        int idx,
        int low,
        int high,
        int l,
        int r) {

        if (r < low || high < l)
            return 0;

        if (l <= low && high <= r)
            return seg[idx];

        int mid = (low + high) / 2;

        return query(
                   2 * idx + 1,
                   low,
                   mid,
                   l,
                   r)
             +
               query(
                   2 * idx + 2,
                   mid + 1,
                   high,
                   l,
                   r);
    }

    int sumRange(int left, int right) {

        return query(
            0,
            0,
            n - 1,
            left,
            right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */