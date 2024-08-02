class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size() , cols = board[0].size() ;

        vector<vector<int>>dirs  = {{0,1}, {1,0} , {-1,0} , {0,-1}};

        function<void(int,int)>dfs = [&](int row , int col){
            if(row < 0 || row >= rows || col < 0  || col >= cols || board[row][col] != 'O') return;

            board[row][col] = '#';

            for(auto t : dirs){
                int new_r = row + t[0];
                int new_c = col + t[1];

                dfs(new_r,new_c); 
            }
        };

        for(int i = 0 ; i <rows ; i++){
            for(int j =0; j <cols ; j++){
                if((i == 0 || i ==rows-1 || j == 0 || j == cols -1) && board[i][j] == 'O'){
                    dfs(i,j);
                }
            }
        } 

        for(int i = 0; i<rows ;i++){
            for(int j = 0 ; j <cols ; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }


    }
};