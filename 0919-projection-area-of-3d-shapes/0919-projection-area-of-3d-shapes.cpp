class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int xy = 0, yz = 0, xz = 0;
        
        for (int i = 0; i < n; ++i) {
            int max_in_row = 0;
            int max_in_col = 0;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    xy++;  
                }
                max_in_row = max(max_in_row, grid[i][j]);  
                max_in_col = max(max_in_col, grid[j][i]);  
            }
            yz += max_in_row;
            xz += max_in_col;
        }
        
        return xy + yz + xz;
    }
};