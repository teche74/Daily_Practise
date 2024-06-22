class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows= board.size() , cols = board[0].size();

        vector<vector<int>>dirs = {{0,1},{0,-1},{1,0} , {-1,0}};

        function<void(int, int)> dfs = [&](int row, int col) {
            if (row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != 'O') {
                return;
            }
            board[row][col] = '#'; 
            for (auto dir : dirs) {
                int new_r = row + dir[0];
                int new_c = col + dir[1];
                dfs(new_r, new_c);
            }
        };

        for (int i = 0; i < rows; ++i) {
            if (board[i][0] == 'O') dfs(i, 0);
            if (board[i][cols - 1] == 'O') dfs(i, cols - 1);
        }
        for (int j = 0; j < cols; ++j) {
            if (board[0][j] == 'O') dfs(0, j);
            if (board[rows - 1][j] == 'O') dfs(rows - 1, j);
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};