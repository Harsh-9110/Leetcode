class Solution {
public:
    int ladderLength(string beginWord,
                     string endWord,
                     vector<string>& wordList) {

        unordered_set<string> words(
            wordList.begin(),
            wordList.end()
        );

        // endWord must exist
        if (!words.count(endWord))
            return 0;

        queue<pair<string,int>> q;

        q.push({beginWord, 1});

        while (!q.empty()) {

            auto [word, steps] =
                q.front();

            q.pop();

            // reached destination
            if (word == endWord)
                return steps;

            for (int i = 0;
                 i < word.size();
                 i++) {

                string temp = word;

                // try all letters
                for (char ch = 'a';
                     ch <= 'z';
                     ch++) {

                    temp[i] = ch;

                    if (words.count(temp)) {

                        q.push({
                            temp,
                            steps + 1
                        });

                        // mark visited
                        words.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};