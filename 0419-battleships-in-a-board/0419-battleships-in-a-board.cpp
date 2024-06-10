class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size() , cols = board[0].size();

        vector<vector<bool>> vis(rows,vector<bool>(cols, false));
        int count =0;

        vector<vector<int>>dirs = {{0,-1} ,{0,1} ,{1,0} , {-1,0}};

        function<void(int,int)> dfs = [&](int row, int col){
            vis[row][col] = true;

            for(auto it : dirs){
                int r = it[0] + row;
                int c = it[1] + col;

                if( r >= 0 && r <rows && c >=0 && c < cols && board[r][c] == 'X' && !vis[r][c]){
                    dfs(r,c);
                } 
            }
        };

        for(int i =0; i <rows; i++){
            for(int j =0;j < cols ; j++){
                if(!vis[i][j] && board[i][j] == 'X'){
                    count++;
                    dfs(i,j);
                }
            }
        } 

        return count;
    }
};