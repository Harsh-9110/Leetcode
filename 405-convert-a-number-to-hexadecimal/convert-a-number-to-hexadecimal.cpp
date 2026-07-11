class Solution {
public:
    string toHex(int num) {

        if (num == 0)
            return "0";

        string hex = "0123456789abcdef";
        string ans = "";

        while (num != 0 && ans.size() < 8) {

            ans += hex[num & 15];

            num >>= 4;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};