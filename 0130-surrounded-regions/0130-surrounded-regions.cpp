class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size() , cols = board[0] .size();

        vector<vector<int>> dirs = {{0,1} , {1,0}  , {-1, 0} , {0,-1} };

        function<void(int,int)> solve = [&](int row, int col){
            if(row >= rows || col >= cols || row < 0 || col < 0 || board[row][col] != 'O' || board[row][col] == '.'){
                return;
            }


            board[row][col] = '.';

            for(auto t : dirs){
                solve(row + t[0] , col + t[1]); 
            }
        };

        for(int i =0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(board[i][j] == 'O' && (i == 0 || i == rows-1 || j == 0 || j == cols -1)){
                    solve(i,j);
                }
            }
        }

        for(int i =0 ; i < rows ; i++){
            for(int j = 0 ; j < cols ; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '.'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};