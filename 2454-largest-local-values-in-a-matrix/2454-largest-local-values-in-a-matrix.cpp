class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {

        vector<vector<int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        
        auto find_max = [&](int row, int col)->int{
            int maxi = grid[row][col];

            for(auto dir : dirs){
                int new_r = row + dir[0];
                int new_c = col + dir[1];

                maxi = max(maxi, grid[new_r][new_c]);
            }
            return maxi;
        };

        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> res(rows - 2, vector<int>(cols - 2));
        
        for(int i = 1; i < rows - 1; i++){
            for(int j = 1; j < cols - 1; j++){
                res[i-1][j-1] = find_max(i, j);
            }
        }

        return res;
    }
};