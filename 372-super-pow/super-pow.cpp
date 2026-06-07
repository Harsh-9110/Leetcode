class Solution {
public:

    static const int MOD = 1337;

    int modPow(int a, int n) {

        long long res = 1;
        long long base = a % MOD;

        while (n > 0) {

            if (n & 1)
                res = (res * base) % MOD;

            base = (base * base) % MOD;
            n >>= 1;
        }

        return res;
    }

    int superPow(int a, vector<int>& b) {

        int res = 1;

        for (int digit : b) {

            res = (modPow(res, 10) *
                   modPow(a, digit)) % MOD;
        }

        return res;
    }
};