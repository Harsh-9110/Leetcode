class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<pair<int,int>> dirs = {
            {-1,-1},{-1,0},{-1,1},
            {0,-1},        {0,1},
            {1,-1},{1,0},{1,1}
        };

        // First pass
        for(int i=0;i<m;i++) {

            for(int j=0;j<n;j++) {

                int live = 0;

                for(auto &[dx,dy] : dirs) {

                    int r = i + dx;
                    int c = j + dy;

                    if(r>=0 && r<m &&
                       c>=0 && c<n &&
                       abs(board[r][c])==1)
                    {
                        live++;
                    }
                }

                if(board[i][j]==1) {

                    if(live<2 || live>3)
                        board[i][j] = -1;
                }
                else {

                    if(live==3)
                        board[i][j] = 2;
                }
            }
        }

        // Second pass
        for(int i=0;i<m;i++) {

            for(int j=0;j<n;j++) {

                if(board[i][j] > 0)
                    board[i][j] = 1;
                else
                    board[i][j] = 0;
            }
        }
    }
};