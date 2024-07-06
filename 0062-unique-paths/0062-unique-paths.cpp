class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp[m][n];
        memset(dp, 0, sizeof(dp));

        // pura right jane ka sirf 1 i tareeka he (from 0 position);

        for(int i = 0; i < m ;i++ ){
            dp[i][0] =1;
        }   

        //  pura down jane ka sirf ek tareeka (from 0 position)

        for(int i=0; i < n ; i++){
            dp[0][i] = 1;
        }

        for(int i=1; i<m;i++){
            for(int j =1; j<n;j++){
                // ab kisi bhi raste ke liye check krna he to simple uske right jane ke kitne tareeke  + down jane ke kitne tarreeke .
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};