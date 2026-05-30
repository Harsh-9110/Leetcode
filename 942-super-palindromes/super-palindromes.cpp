class Solution {
public:

    bool isPalindrome(long long x) {

        string s = to_string(x);
        string t = s;

        reverse(t.begin(), t.end());

        return s == t;
    }

    int superpalindromesInRange(string left,
                                string right) {

        long long L = stoll(left);
        long long R = stoll(right);

        int ans = 0;

        // odd length palindromes
        for (long long k = 1;
             k < 100000;
             k++) {

            string s = to_string(k);

            string t = s;
            t.pop_back();

            reverse(t.begin(), t.end());

            long long root =
                stoll(s + t);

            long long sq = root * root;

            if (sq > R)
                break;

            if (sq >= L &&
                isPalindrome(sq))
                ans++;
        }

        // even length palindromes
        for (long long k = 1;
             k < 100000;
             k++) {

            string s = to_string(k);

            string t = s;

            reverse(t.begin(),
                    t.end());

            long long root =
                stoll(s + t);

            long long sq = root * root;

            if (sq > R)
                break;

            if (sq >= L &&
                isPalindrome(sq))
                ans++;
        }

        return ans;
    }
};