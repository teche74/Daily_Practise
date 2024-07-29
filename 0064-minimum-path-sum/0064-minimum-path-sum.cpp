class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size() ,cols = grid[0] .size();

        int dp[201][201];

        // function<int(int,int)> solve = [&](int row, int col){
        //     if(row == rows-1 && col == cols-1){
        //         return grid[row][col];
        //     }

        //     if(row < 0 || col < 0 || row >= rows || col >= cols) return 1000000;

        //     if(dp[row][col] != -1) return dp[row][col];

        //     return dp[row][col] = grid[row][col] + min(solve(row+1,col) , solve(row,col+1));
        // };

        // memset(dp, -1, sizeof(dp));

        // return solve(0,0);


        memset(dp, 0 , sizeof(dp));

        for(int i = 0; i <rows;  i++){
            dp[i][0] = i == 0 ? grid[i][0] : dp[i-1][0] + grid[i][0];   
        }

        for(int j = 0 ; j <cols ; j++){
            dp[0][j] =  j== 0 ? grid[0][j] : dp[0][j-1] + grid[0][j];
        }

        for(int i =1; i <rows; i++){
            for(int j = 1; j <cols ; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j] , dp[i][j-1]);
            }
        }

        return dp[rows-1][cols-1]; 
    }
};