class Solution {
public:
    vector<int> maxArray(vector<int>& nums, int k) {
        vector<int> st;
        int drop = nums.size() - k;

        for (int num : nums) {
            while (!st.empty() && drop > 0 && st.back() < num) {
                st.pop_back();
                drop--;
            }
            st.push_back(num);
        }

        st.resize(k);
        return st;
    }

    bool greater(vector<int>& a, int i, vector<int>& b, int j) {
        while (i < a.size() && j < b.size() && a[i] == b[j]) {
            i++;
            j++;
        }
        if (j == b.size()) return true;
        if (i == a.size()) return false;
        return a[i] > b[j];
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> res;
        int i = 0, j = 0;

        while (i < a.size() || j < b.size()) {
            if (greater(a, i, b, j))
                res.push_back(a[i++]);
            else
                res.push_back(b[j++]);
        }

        return res;
    }

    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;

        int start = max(0, k - (int)nums2.size());
        int end = min(k, (int)nums1.size());

        for (int i = start; i <= end; i++) {
            vector<int> a = maxArray(nums1, i);
            vector<int> b = maxArray(nums2, k - i);
            vector<int> cur = merge(a, b);

            if (ans.empty() || greater(cur, 0, ans, 0))
                ans = cur;
        }

        return ans;
    }
};