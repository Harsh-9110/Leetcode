class Solution {
public:

    bool canAllocate(vector<int>& candies,
                     long long k,
                     long long x) {

        long long children = 0;

        for (int pile : candies) {

            children += pile / x;

            if (children >= k)
                return true;
        }

        return false;
    }

    int maximumCandies(vector<int>& candies,
                       long long k) {

        long long total = 0;

        for (int x : candies)
            total += x;

        if (total < k)
            return 0;

        long long left = 1;
        long long right =
            *max_element(
                candies.begin(),
                candies.end()
            );

        long long ans = 0;

        while (left <= right) {

            long long mid =
                left + (right - left) / 2;

            if (canAllocate(
                    candies,
                    k,
                    mid)) {

                ans = mid;
                left = mid + 1;
            }
            else {

                right = mid - 1;
            }
        }

        return (int)ans;
    }
};