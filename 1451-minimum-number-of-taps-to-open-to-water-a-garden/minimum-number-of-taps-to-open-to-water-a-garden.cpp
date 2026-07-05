class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

        vector<int> reach(n + 1, 0);

        for (int i = 0; i <= n; i++) {

            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);

            reach[left] = max(reach[left], right);
        }

        int taps = 0;
        int currEnd = 0;
        int far = 0;

        for (int i = 0; i < n; i++) {

            far = max(far, reach[i]);

            if (i == currEnd) {

                if (far <= i)
                    return -1;

                taps++;
                currEnd = far;
            }
        }

        return taps;
    }
};