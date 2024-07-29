class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int rows = mat.size() , cols = mat[0].size();

        if(mat[0][0] == 1 || mat[rows-1][cols-1] == 1) return 0;

        int dp[101][101];

        function<int(int,int)>solve = [&](int row , int col){
            if(row == rows-1 && col == cols -1){
                return 1;
            }

            if( row < 0 || row >= rows || col < 0 || col >= cols || mat[row][col] == 1){
                return 0;
            }

            if(dp[row][col] != -1) return dp[row][col];

            int left = solve(row+1,col);
            int right = solve(row,col+1);

            return dp[row][col] = left + right ; 
        }; 

        memset(dp, -1, sizeof(dp));
        return solve(0,0);
    }
};