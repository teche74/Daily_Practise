class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[101][101];
        function<int(int,int)> solve = [&](int row , int col){
            if(row == m-1 && col == n-1){
                return 1;
            }

            if(row < 0 || row >= m || col < 0 || col >= n){
                return 0;
            }

            if(dp[row][col] != -1) return dp[row][col];

            int left = solve(row+1,col);
            int right = solve(row, col+1);

            return dp[row][col] = left + right;
        };

        memset(dp,-1,sizeof(dp));
        return solve(0,0);
    }
};