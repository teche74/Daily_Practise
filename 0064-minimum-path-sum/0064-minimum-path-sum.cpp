class Solution {
public:
    int solve(int row, int col, vector<vector<int>>&arr, vector<vector<int>> &memo){
        if(row >= arr.size() || col >= arr[0].size()){
            return INT_MAX;
        }

        if(memo[row][col] != -1){
            return memo[row][col];
        }

        if(row == arr.size()-1 && col == arr[0].size()-1){
            return arr[row][col];
        }

        int down = solve(row+1,col,arr, memo);
        int right = solve(row, col+1,arr, memo);

        return memo[row][col] = arr[row][col] + min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        // vector<vector<int>>memo(rows, vector<int>(cols,-1));
        // return solve(0,0,grid,memo);
        int rows = grid.size(), cols = grid[0].size();

        vector<vector<int>>dp(rows, vector<int>(cols,0));
        
        dp[0][0] = grid[0][0];

        for(int i =1; i < rows; i++){
            dp[i][0] += dp[i-1][0] + grid[i][0]; 
        }

        for(int j=1;j<cols;j++){
            dp[0][j] += dp[0][j-1] + grid[0][j];
        }

        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[rows-1][cols-1];
    }
};