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

    string findRoot(string word) {

        TrieNode* node = root;

        string prefix = "";

        for (char c : word) {

            int idx = c - 'a';

            // no root exists
            if (node->children[idx] == NULL)
                return word;

            node = node->children[idx];

            prefix += c;

            // shortest root found
            if (node->isEnd)
                return prefix;
        }

        return word;
    }

    string replaceWords(vector<string>& dictionary,
                        string sentence) {

        // build trie
        for (string& rootWord : dictionary)
            insert(rootWord);

        stringstream ss(sentence);

        string word;

        string ans = "";

        while (ss >> word) {

            ans += findRoot(word);
            ans += " ";
        }

        ans.pop_back();

        return ans;
    }
};