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

class WordDictionary {

public:

    TrieNode* root;

    WordDictionary() {

        root = new TrieNode();
    }

    void addWord(string word) {

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

    bool dfs(string& word,
             int pos,
             TrieNode* node) {

        if (pos == word.size())
            return node->isEnd;

        char c = word[pos];

        // wildcard
        if (c == '.') {

            for (int i = 0; i < 26; i++) {

                if (node->children[i] != NULL) {

                    if (dfs(word,
                            pos + 1,
                            node->children[i])) {

                        return true;
                    }
                }
            }

            return false;
        }

        // normal character
        int idx = c - 'a';

        if (node->children[idx] == NULL)
            return false;

        return dfs(word,
                   pos + 1,
                   node->children[idx]);
    }

    bool search(string word) {

        return dfs(word, 0, root);
    }
};