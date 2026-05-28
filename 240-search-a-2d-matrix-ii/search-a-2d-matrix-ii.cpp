class Solution {
public:
    bool searchMatrix(
        vector<vector<int>>& matrix,
        int target) {

        int m = matrix.size();
        int n = matrix[0].size();

        int row = 0;
        int col = n - 1;

        while (row < m &&
               col >= 0) {

            int curr =
                matrix[row][col];

            if (curr == target)
                return true;

            // eliminate column
            if (curr > target) {

                col--;
            }
            else {

                // eliminate row
                row++;
            }
        }

        return false;
    }
};