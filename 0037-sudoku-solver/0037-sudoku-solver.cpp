class Solution {
public:
    bool placed(vector<vector<char>>& board, int row, int col, char val){
        for(int i= 0; i <9 ;i++){
            if(board[row][i] == val) return false;
            if(board[i][col] == val) return false;
            if(board[(row/3)*3  + (i/3)] [(col/3)*3  + (i % 3)] == val) return false;
        }
        return true;
    }
    bool util(vector<vector<char>>& board){
        int rows = board.size()  , cols = board[0].size();

        for(int i =0; i <rows ; i++){
            for(int j = 0; j<cols ; j++){
                if(board[i][j] == '.'){
                    for(char ch = '1' ; ch <= '9' ; ch++ ){
                        if(placed(board,i,j,ch) == true){
                            board[i][j] = ch;


                            if( util(board) == true ) return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        util(board);
    }
};