class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int size = board.size();

        vector<vector<int>>row_check(size,vector<int>(size,0));
        vector<vector<int>>col_check(size,vector<int>(size,0));
        vector<vector<int>>grid_check(size,vector<int>(size,0));


        for(int i = 0 ;i < size ; i++){
            for(int j = 0; j < size ; j++){
                if(board[i][j] != '.'){
                    int val = board[i][j] - '0';

                    int k  = (i/3) * 3 + (j/3);

                    if(row_check[i][val-1]++ || col_check[val-1][j]++ || grid_check[val-1][k]++ ) return false;
                }
            }
        }

        return true;

    }
};