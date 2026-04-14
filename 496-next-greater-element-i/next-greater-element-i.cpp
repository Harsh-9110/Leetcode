class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;

        // process nums2
        for (int x : nums2) {
            while (!st.empty() && x > st.top()) {
                mp[st.top()] = x;
                st.pop();
            }
            st.push(x);
        }

        // remaining → no greater element
        while (!st.empty()) {
            mp[st.top()] = -1;
            st.pop();
        }

        // build result
        vector<int> ans;
        for (int x : nums1) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};