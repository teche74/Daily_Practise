class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        
        int mini_r = rows, maxi_r = -1;
        int mini_c = cols, maxi_c = -1;
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(grid[i][j] == 1) {
                    mini_r = min(mini_r, i);
                    maxi_r = max(maxi_r, i);
                    mini_c = min(mini_c, j);
                    maxi_c = max(maxi_c, j);
                }
            }
        }
        
        if (mini_r == rows) {
            return 0;
        }
        
        return (maxi_r - mini_r + 1) * (maxi_c - mini_c + 1);
    }
};