class Solution {
public:
    vector<string> ans;
    vector<string> mp = {
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };
    void dfs(int idx,
             string &digits,
             string curr) {

        if (idx == digits.size()) {
            ans.push_back(curr);
            return;
        }
        string letters = mp[digits[idx] - '0'];
        for (char ch : letters) {

            dfs(idx + 1,
                digits,
                curr + ch);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        dfs(0, digits, "");
        return ans;
    }
};