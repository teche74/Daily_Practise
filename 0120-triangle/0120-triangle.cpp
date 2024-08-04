class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rows = triangle.size(), cols = triangle[0].size();
        int dp[201][201];

        function<int(int,int)>solve = [&](int row ,int col){
            if(row == rows){
                return 0;
            }

            if(dp[row][col] != -1) return dp[row][col];
            

            return dp[row][col] = triangle[row][col] + min(solve(row+1,col),solve(row+1,col+1));
        } ;
        memset(dp,-1,sizeof(dp));
        return solve(0,0);
    }
};