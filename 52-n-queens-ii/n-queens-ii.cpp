class Solution {
public:
    int ans = 0;

    void backtrack(int row, int n,
                   unordered_set<int>& col,
                   unordered_set<int>& diag1,
                   unordered_set<int>& diag2) {

        if (row == n) {
            ans++;
            return;
        }

        for (int c = 0; c < n; c++) {

            if (col.count(c) ||
                diag1.count(row - c) ||
                diag2.count(row + c))
                continue;

            // place queen
            col.insert(c);
            diag1.insert(row - c);
            diag2.insert(row + c);

            backtrack(row + 1, n, col, diag1, diag2);

            // remove queen
            col.erase(c);
            diag1.erase(row - c);
            diag2.erase(row + c);
        }
    }

    int totalNQueens(int n) {
        unordered_set<int> col, diag1, diag2;

        backtrack(0, n, col, diag1, diag2);

        return ans;
    }
};