class Solution {
public:

    bool canShip(vector<int>& weights,
                 int days,
                 int capacity) {

        int usedDays = 1;
        int currWeight = 0;

        for (int w : weights) {

            // start new day
            if (currWeight + w > capacity) {

                usedDays++;

                currWeight = 0;
            }

            currWeight += w;
        }

        return usedDays <= days;
    }

    int shipWithinDays(vector<int>& weights,
                       int days) {

        int left =
            *max_element(weights.begin(),
                         weights.end());

        int right =
            accumulate(weights.begin(),
                       weights.end(),
                       0);

        int ans = right;

        while (left <= right) {

            int mid =
                left + (right - left) / 2;

            if (canShip(weights,
                        days,
                        mid)) {

                ans = mid;

                right = mid - 1;
            }
            else {

                left = mid + 1;
            }
        }

        return ans;
    }
};