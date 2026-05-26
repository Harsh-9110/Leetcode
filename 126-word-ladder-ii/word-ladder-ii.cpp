class Solution {
public:

    unordered_map<string,
                  vector<string>> parent;

    vector<vector<string>> ans;

    void backtrack(string word,
                   string beginWord,
                   vector<string>& path) {

        if (word == beginWord) {

            vector<string> temp = path;

            reverse(temp.begin(),
                    temp.end());

            ans.push_back(temp);

            return;
        }

        for (string& p : parent[word]) {

            path.push_back(p);

            backtrack(p,
                      beginWord,
                      path);

            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList) {

        unordered_set<string> words(
            wordList.begin(),
            wordList.end()
        );

        if (!words.count(endWord))
            return {};

        queue<string> q;

        q.push(beginWord);

        unordered_set<string> visited;

        visited.insert(beginWord);

        bool found = false;

        while (!q.empty() && !found) {

            int size = q.size();

            unordered_set<string> levelVisited;

            for (int s = 0;
                 s < size;
                 s++) {

                string word = q.front();

                q.pop();

                string original = word;

                for (int i = 0;
                     i < word.size();
                     i++) {

                    char oldChar = word[i];

                    for (char ch = 'a';
                         ch <= 'z';
                         ch++) {

                        word[i] = ch;

                        if (words.count(word)
                            &&
                            !visited.count(word)) {

                            if (!levelVisited.count(word)) {

                                q.push(word);

                                levelVisited.insert(word);
                            }

                            parent[word]
                                .push_back(original);

                            if (word == endWord)
                                found = true;
                        }
                    }

                    word[i] = oldChar;
                }
            }

            for (auto& w : levelVisited)
                visited.insert(w);
        }

        if (!found)
            return {};

        vector<string> path;

        path.push_back(endWord);

        backtrack(endWord,
                  beginWord,
                  path);

        return ans;
    }
};