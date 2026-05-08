class Solution {
public:
    int m, n;

    bool dfs(vector<vector<char>>& board, string& word,
             int i, int j, int k) {

        // matched whole word
        if (k == word.size())
            return true;

        // invalid
        if (i < 0 || j < 0 || i >= m || j >= n ||
            board[i][j] != word[k])
            return false;

        char temp = board[i][j];
        board[i][j] = '#'; // mark visited

        bool found =
            dfs(board, word, i + 1, j, k + 1) ||
            dfs(board, word, i - 1, j, k + 1) ||
            dfs(board, word, i, j + 1, k + 1) ||
            dfs(board, word, i, j - 1, k + 1);

        board[i][j] = temp; // backtrack

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }

        return false;
    }
};