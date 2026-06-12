class Solution {
public:

    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;

    vector<string> dfs(string& s, int start) {

        if (memo.count(start))
            return memo[start];

        vector<string> res;

        if (start == s.size()) {
            res.push_back("");
            return res;
        }

        for (int len = 1;
             start + len <= s.size();
             len++) {

            string word =
                s.substr(start, len);

            if (!dict.count(word))
                continue;

            vector<string> suffixes =
                dfs(s, start + len);

            for (string suffix : suffixes) {

                if (suffix.empty())
                    res.push_back(word);
                else
                    res.push_back(
                        word + " " + suffix
                    );
            }
        }

        return memo[start] = res;
    }

    vector<string> wordBreak(
        string s,
        vector<string>& wordDict) {

        dict.insert(
            wordDict.begin(),
            wordDict.end()
        );

        return dfs(s, 0);
    }
};