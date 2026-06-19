class Solution {
public:
    int countVowelPermutation(int n) {

        const long long MOD = 1e9 + 7;

        long long a = 1;
        long long e = 1;
        long long i = 1;
        long long o = 1;
        long long u = 1;

        for (int len = 2; len <= n; len++) {

            long long na = (e + i + u) % MOD;
            long long ne = (a + i) % MOD;
            long long ni = (e + o) % MOD;
            long long no = i % MOD;
            long long nu = (i + o) % MOD;

            a = na;
            e = ne;
            i = ni;
            o = no;
            u = nu;
        }

        return (a + e + i + o + u) % MOD;
    }
};