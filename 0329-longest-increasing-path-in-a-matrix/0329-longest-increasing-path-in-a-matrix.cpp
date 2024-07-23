class Solution {
public:
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
        int rows = matrix.size() , cols = matrix[0].size();

        vector<vector<int>>dirs = {{0,1},{1,0}, {-1,0} ,{0,-1}};

        int dp[201][201];
        memset(dp,-1,sizeof(dp));

        function <int(int,int)>solve = [&](int row , int col){
            if (dp[row][col] != -1) return dp[row][col];

            int max_len = 1;

            for (auto dir : dirs) {
                int new_r = row + dir[0], new_c = col + dir[1];

                if (new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols && matrix[new_r][new_c] > matrix[row][col]) {
                    int len = 1 + solve(new_r, new_c);
                    max_len = max(max_len, len);
                }

            }

            return dp[row][col] = max_len;
        };

        int res = 0;

        for(int i = 0 ;i < rows ; i++){
            for(int j = 0 ;j < cols ; j++){
                res = max(res,solve(i,j));
            }
        }

        return res;
    }
};