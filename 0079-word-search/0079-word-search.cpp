class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size() , cols = board[0].size();

        if (rows * cols < word.size()) return false;

        unordered_map<char, int> wordCount, boardCount;
        for (char c : word) wordCount[c]++;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                boardCount[board[i][j]]++;
            }
        }
        
        
        for (auto& wc : wordCount) {
            if (boardCount[wc.first] < wc.second) return false;
        }

        vector<vector<int>>dirs = {{0,1},{1,0},{-1,0},{0,-1}};

        function<bool(int,int,int)> dfs = [&](int row, int col, int len){
            if(len == word.size()) return true;

            if(row < 0 || row >= rows || col < 0 || col >= cols || board[row][col] != word[len]) 
                return false;

            char ch = board[row][col];
            board[row][col] = '.';
            len++;

            for(auto t : dirs){
                int new_r = t[0] + row;
                int new_c = t[1] + col;

                if(dfs(new_r, new_c, len)) {
                    board[row][col] = ch;  
                    return true;
                }
            }
            board[row][col] = ch;
            return false;
        };

        for(int i =0; i <rows;  i++){
            for(int j =0; j< cols ; j++){
                if(board[i][j] == word[0] && dfs(i,j,0)){
                    return true;
                }
            }
        } 
        return false;
    }
};