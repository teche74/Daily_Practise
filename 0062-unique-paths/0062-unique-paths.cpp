class Solution {
public:
    int dp[101][101];

    int solve(int row, int col , int rows , int cols){
        if(row == rows-1 && col == cols -1) return 1;
        if(row >= rows || col >= cols) return 0;
        if(dp[row][col] != -1) return dp[row][col];

        return dp[row][col] = solve(row+1,col, rows, cols) + solve(row , col+1 , rows, cols);
    }
    int uniquePaths(int m, int n) {
        memset(dp, -1,sizeof(dp));
        return solve(0 ,0 , m , n);
    }
};