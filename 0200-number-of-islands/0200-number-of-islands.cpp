class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size() , cols = grid[0].size();

        vector<vector<bool>>vis(rows,vector<bool>(cols,false));

        vector<vector<int>> dirs = {{0,1}, {1,0} ,{-1,0} , {0,-1}};

        function<void(int,int)> solve = [&](int row, int col){
            if(row >= rows || col >= cols || col < 0 || row < 0 || vis[row][col] || grid[row][col] != '1'){
                return;
            }

            vis[row][col] = true;

            for(auto t : dirs){
                int new_r = row + t[0];
                int new_c = col + t[1];

                solve(new_r , new_c);
            }
        };

        int count  = 0;

        for(int i = 0; i < rows ; i++){
            for(int j =0; j < cols ; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    count++;
                    solve(i,j);
                }
            }
        }

        return count;
    }
};