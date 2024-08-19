class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size()  , cols = board[0].size();

        vector<vector<int>>dirs = {{0,1},  {1,0} , {-1,0} , {0,-1}};

        function<bool(int,int,int)> solve = [&](int index, int row, int col){
            if(index >= word.size()) return true;
            if(row >= rows || col  >= cols || row < 0 || col  < 0 || board[row][col] == '.' || board[row][col] != word[index]) return false;

            char ch  = board[row][col];
            board[row][col] = '.';
            index++;

            if(solve(index , row+1,col) || solve(index , row,col+1) || solve(index , row-1, col) || solve(index, row, col-1)) return true;

            board[row][col] = ch;
            return false;
        };

        for(int i = 0; i  < rows; i++){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == word[0] && solve(0,i,j)){
                    return true;
                }
            }
        }

        return false;
    }
};