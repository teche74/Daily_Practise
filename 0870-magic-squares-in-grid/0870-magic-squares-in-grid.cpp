class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int count = 0;
        
        auto check = [&](int row, int col) -> bool {
            if (grid[row][col] != 5) return false;  
            
            vector<int> vals = {
                grid[row-1][col-1], grid[row-1][col], grid[row-1][col+1],
                grid[row][col-1],   grid[row][col],   grid[row][col+1],
                grid[row+1][col-1], grid[row+1][col], grid[row+1][col+1]
            };

            vector<int> temp(10, 0);
            for (int val : vals) {
                if (val < 1 || val > 9 || temp[val]) return false;
                temp[val] = 1;
            }
            
            return (vals[0] + vals[1] + vals[2] == 15) && 
                   (vals[3] + vals[4] + vals[5] == 15) &&
                   (vals[6] + vals[7] + vals[8] == 15) &&
                   (vals[0] + vals[3] + vals[6] == 15) &&
                   (vals[1] + vals[4] + vals[7] == 15) &&
                   (vals[2] + vals[5] + vals[8] == 15) &&
                   (vals[0] + vals[4] + vals[8] == 15) &&
                   (vals[2] + vals[4] + vals[6] == 15);
        };
        
        for (int i = 1; i < rows - 1; i++) {
            for (int j = 1; j < cols - 1; j++) {
                if (check(i, j)) {
                    count++;
                }
            }
        }
        return count;
    }
};