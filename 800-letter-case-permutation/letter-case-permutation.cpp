class Solution {
public:

    vector<string> ans;

    void backtrack(string& s,
                   int idx,
                   string curr) {

        if (idx == s.size()) {
            ans.push_back(curr);
            return;
        }

        if (isdigit(s[idx])) {

            backtrack(
                s,
                idx + 1,
                curr + s[idx]
            );
        }
        else {

            backtrack(
                s,
                idx + 1,
                curr + (char)tolower(s[idx])
            );

            backtrack(
                s,
                idx + 1,
                curr + (char)toupper(s[idx])
            );
        }
    }

    vector<string> letterCasePermutation(string s) {

        backtrack(s, 0, "");

        return ans;
    }
};