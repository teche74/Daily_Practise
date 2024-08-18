class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size() , cols = grid[0].size();
        int dp[201][201];

        function<int(int,int)> solve = [&](int row, int col){
            if(row >=rows || col >= cols) return (int)1e9;
            if(row == rows-1 && col == cols-1) return grid[row][col];

            if(dp[row][col] != -1) return dp[row][col];

            return dp[row][col] = grid[row][col] + min(solve(row+1,col), solve(row,col+1));
        };
        memset(dp,-1,sizeof(dp));
        return solve(0,0);
    }
};