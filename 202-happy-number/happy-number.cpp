class Solution {
public:

    int nextNumber(int n) {

        int sum = 0;

        while (n) {

            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        return sum;
    }

    bool isHappy(int n) {

        unordered_set<int> seen;

        while (n != 1 && !seen.count(n)) {

            seen.insert(n);
            n = nextNumber(n);
        }

        return n == 1;
    }
};