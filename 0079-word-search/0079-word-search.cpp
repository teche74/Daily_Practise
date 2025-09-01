#define  loop(integer , start , stop) for(int integer = start ; integer < stop; integer++)

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        int index = 0;


        function<bool(int,int)>dfs= [&](int row, int col){
            if(index == word.size()) return true;
            if(row >=rows || col >= cols || row < 0 || col < 0 || board[row][col] != word[index]) return false;
            char ch = board[row][col];
            board[row][col] = '.';
            index++;

            bool cond = dfs(row+1 , col) || dfs(row-1, col) || dfs(row, col+1) || dfs(row, col-1);

            index--;
            board[row][col] = ch;
            return cond;
        };

        loop(i,0,rows){
            loop(j,0,cols){
                if(board[i][j] == word[0]){
                    if(dfs(i,j))
                        return true;
                }
            }
        }
        return false;
    }
};