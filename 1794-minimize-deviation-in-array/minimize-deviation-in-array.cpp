class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mn = INT_MAX;

        // Convert all numbers to even
        for (int num : nums) {
            if (num % 2 == 1)
                num *= 2;
            pq.push(num);
            mn = min(mn, num);
        }

        int ans = INT_MAX;

        while (!pq.empty()) {
            int mx = pq.top();
            pq.pop();

            ans = min(ans, mx - mn);

            if (mx % 2 == 1)
                break;

            mx /= 2;
            mn = min(mn, mx);
            pq.push(mx);
        }

        return ans;
    }
};