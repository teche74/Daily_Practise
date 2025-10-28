class Solution {
public:
    bool valid(vector<vector<char>>& board , int row, int col , char ch){
        for(int i =0; i < 9 ;i++){
            if(board[row][i] == ch) return false;
            if(board[i][col] == ch) return false;
            if(board[(row/3)*3 + i/3] [(col/3)*3 + i%3] == ch) return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        int rows = board.size() ,  cols = board[0].size();

        for(int i = 0 ; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == '.'){
                    for(char ch = '1' ; ch <= '9'; ch++){
                        if(valid(board , i,j, ch)){
                            board[i][j] = ch;

                            if(!solve(board)){
                                board[i][j] = '.';
                            }
                            else return true;
                        }
                    }

                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};