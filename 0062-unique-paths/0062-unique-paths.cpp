class Solution {
public:
    int uniquePaths(int m, int n) {
        // int dp[101][101];
        // function<int(int,int)> solve = [&](int row , int col){
        //     if(row == m-1 && col == n-1){
        //         return 1;
        //     }

        //     if(row < 0 || row >= m || col < 0 || col >= n){
        //         return 0;
        //     }

        //     if(dp[row][col] != -1) return dp[row][col];

        //     int left = solve(row+1,col);
        //     int right = solve(row, col+1);

        //     return dp[row][col] = left + right;
        // };

        // memset(dp,-1,sizeof(dp));
        // return solve(0,0);

        int dp[m][n];
        memset(dp, 0 ,sizeof(dp));

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ;j < n ;j++){
                if(i == 0 || j == 0){
                    dp[i][j]  =1;
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};