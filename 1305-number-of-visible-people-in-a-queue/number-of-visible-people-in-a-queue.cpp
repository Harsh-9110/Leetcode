class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {

        int n = heights.size();

        vector<int> ans(n);

        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            int cnt = 0;

            while (!st.empty() &&
                   heights[i] > st.top()) {

                cnt++;
                st.pop();
            }

            if (!st.empty())
                cnt++;

            ans[i] = cnt;

            st.push(heights[i]);
        }

        return ans;
    }
};