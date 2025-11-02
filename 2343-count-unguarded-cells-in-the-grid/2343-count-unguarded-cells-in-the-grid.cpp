class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        
        vector<vector<int>>board(m , vector<int>(n, -1));

        for(auto t : walls){
            board[t[0]][t[1]] = 2;
        }

        int total_cells = (m * n) - walls.size();  

        for(auto t : guards){
            if (board[t[0]][t[1]] != 1){
                board[t[0]][t[1]] = 1;
                total_cells--;
            }
        }

        for(auto t : guards){
            int row = t[0] , col = t[1];
            

            for(int j = row-1; j >= 0; j--){
                if(board[j][col] == 2 || board[j][col] == 1) break;
                total_cells -= (board[j][col] == -1);
                board[j][col] = 3;
            }

            for(int j = row+1; j < m; j++){
                if(board[j][col] == 2 || board[j][col] == 1) break;
                total_cells-=(board[j][col] == -1);
                board[j][col] = 3;
            }

            for(int j = col-1 ; j >= 0; j--){
                if(board[row][j] == 2 ||  board[row][j] == 1) break;
                total_cells-=(board[row][j] == -1);
                board[row][j] = 3;
            }

            for(int j = col + 1;j < n; j++){
                if(board[row][j] == 2 ||  board[row][j] == 1)break;
                total_cells-=(board[row][j] == -1);
                board[row][j] = 3;
            }
        }

        return total_cells;
    }
};