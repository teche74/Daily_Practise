class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        

        vector<vector<int>> pre_x(m + 1, vector<int>(n + 1, 0));
        vector<vector<int>> pre_y(m + 1, vector<int>(n + 1, 0));
        
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                pre_x[i][j] = pre_x[i - 1][j] + pre_x[i][j - 1] - pre_x[i - 1][j - 1] + (grid[i - 1][j - 1] == 'X' ? 1 : 0);
                pre_y[i][j] = pre_y[i - 1][j] + pre_y[i][j - 1] - pre_y[i - 1][j - 1] + (grid[i - 1][j - 1] == 'Y' ? 1 : 0);
            }
        }
        
        int count = 0;
        
        for (int i2 = 0; i2 < m; ++i2) {
            for (int j2 = 0; j2 < n; ++j2) {
                    
                int xCount = pre_x[i2 + 1][j2 + 1] - pre_x[0][j2 + 1] - pre_x[i2 + 1][0] + pre_x[0][0];
                int yCount = pre_y[i2 + 1][j2 + 1] - pre_y[0][j2 + 1] - pre_y[i2 + 1][0] + pre_y[0][0];
                            
                if (xCount > 0 && xCount == yCount) {
                    ++count;
                }
            
            }
        }

        
        return count;
    }
};