class Solution {
public:
    void floodfill(vector<vector<int>>& grid, int r, int c, int color) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] != 0)
            return;
        
        grid[r][c] = color;
        
        floodfill(grid, r - 1, c, color);
        floodfill(grid, r + 1, c, color);
        floodfill(grid, r, c - 1, color);
        floodfill(grid, r, c + 1, color);
    }

    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int max_color = 0;

        vector<vector<int>> my_grid(n * 3, vector<int>(n * 3, 0));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '/') {
                    my_grid[i * 3 + 0][j * 3 + 2] = -1;
                    my_grid[i * 3 + 1][j * 3 + 1] = -1;
                    my_grid[i * 3 + 2][j * 3 + 0] = -1;
                } else if (grid[i][j] == '\\') {
                    my_grid[i * 3 + 0][j * 3 + 0] = -1;
                    my_grid[i * 3 + 1][j * 3 + 1] = -1;
                    my_grid[i * 3 + 2][j * 3 + 2] = -1;
                }
            }
        }

        for (int i = 0; i < n * 3; ++i) {
            for (int j = 0; j < n * 3; ++j) {
                if (my_grid[i][j] == 0) {
                    ++max_color;
                    floodfill(my_grid, i, j, max_color);
                }
            }
        }
        
        return max_color;
    }
};
