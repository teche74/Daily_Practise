class Solution {
public:
    int dp[201][201];

    int solve(int row, int col , vector<vector<int>> & triangles){
        if(row >= triangles.size() || col >= triangles.size()){
            return 1e9;
        }

        if(row == triangles.size() - 1){
            return triangles[row][col];
        }

        if(dp[row][col] != -1) return dp[row][col];


        return dp[row][col] = triangles[row][col] +  min(solve(row+1, col +1 , triangles), solve(row+1, col , triangles));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp, -1, sizeof(dp));
        return  solve(0 , 0 , triangle);
    }
};