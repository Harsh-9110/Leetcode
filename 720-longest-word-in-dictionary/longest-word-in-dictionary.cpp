class TrieNode {
public:

    TrieNode* children[26];

    bool isEnd;

    TrieNode() {

        isEnd = false;

        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Solution {
public:

    TrieNode* root = new TrieNode();

    void insert(string word) {

        TrieNode* node = root;

        for (char c : word) {

            int idx = c - 'a';

            if (node->children[idx] == NULL) {

                node->children[idx] =
                    new TrieNode();
            }

            node = node->children[idx];
        }

        node->isEnd = true;
    }

    bool canBuild(string word) {

        TrieNode* node = root;

        for (char c : word) {

            int idx = c - 'a';

            node = node->children[idx];

            // every prefix must exist
            if (node == NULL || !node->isEnd)
                return false;
        }

        return true;
    }

    string longestWord(vector<string>& words) {

        for (string& word : words)
            insert(word);

        string ans = "";

        for (string& word : words) {

            if (canBuild(word)) {

                if (word.size() > ans.size() ||

                   (word.size() == ans.size() &&
                    word < ans)) {

                    ans = word;
                }
            }
        }

        return ans;
    }
};