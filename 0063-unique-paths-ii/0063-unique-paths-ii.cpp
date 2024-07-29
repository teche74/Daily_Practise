class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int rows = mat.size() , cols = mat[0].size();

        if(mat[0][0] == 1 || mat[rows-1][cols-1] == 1) return 0;

        // int dp[101][101];

        // function<int(int,int)>solve = [&](int row , int col){
        //     if(row == rows-1 && col == cols -1){
        //         return 1;
        //     }

        //     if( row < 0 || row >= rows || col < 0 || col >= cols || mat[row][col] == 1){
        //         return 0;
        //     }

        //     if(dp[row][col] != -1) return dp[row][col];

        //     int left = solve(row+1,col);
        //     int right = solve(row,col+1);

        //     return dp[row][col] = left + right ; 
        // }; 

        // memset(dp, -1, sizeof(dp));
        // return solve(0,0);

        int dp[rows][cols];

        memset(dp, 0, sizeof(dp));

        dp[0][0] =1;

        for(int i =0 ; i < rows ; i++){
            for(int j = 0 ;j < cols ; j++){
                if(i == 0 || j == 0){
                    if(mat[i][j] == 1) dp[i][j] = 0;
                    else{
                        if(i > 0) dp[i][j] = dp[i-1][j];
                        else if(j > 0) dp[i][j] = dp[i][j-1];
                    }
                }
                if(mat[i][j] != 1 && i > 0 && j> 0){
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[rows-1][cols-1];
    }
};