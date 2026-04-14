class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int> ans(n, 0);
        stack<int> st; // stores indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temp[i] > temp[st.top()]) {
                int prev = st.top();
                st.pop();
                ans[prev] = i - prev;
            }
            st.push(i);
        }

        return ans;
    }
};