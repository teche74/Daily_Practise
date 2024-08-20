class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size() , cols = grid[0].size();

        bool vis[rows][cols];
        memset(vis,false, sizeof(vis));

        int islands = 0;

        vector<vector<int>>dirs = {{0,1} , {1,0} , {-1,0} , {0,-1}};

        function<void(int,int)> solve = [&](int row, int col){
            if(row >= rows || col >= cols || row < 0 || col < 0 || grid[row][col] != '1' || vis[row][col]){
                return;
            }

            vis[row][col] = true;

            for(auto t : dirs){
                int new_r = row + t[0];
                int new_c = col + t[1];
                solve(new_r , new_c);
            }
        };

        for(int i = 0 ;i < rows; i++){
            for(int j = 0 ;j < cols;  j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    solve(i,j);
                    islands++;
                }
            }
        }

        return islands;
    }
};