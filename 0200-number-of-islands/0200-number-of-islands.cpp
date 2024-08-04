class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size() , cols = grid[0].size();

        int count = 0;

        bool vis[rows][cols];
        memset(vis, false,sizeof(vis));

        vector<vector<int>> dirs = {{1,0} ,{0,1} ,{-1,0},{0,-1}};

        function<void(int,int)> bfs = [&](int row, int col){
            if(row < 0 || col < 0 || row >= rows || col >=cols || grid[row][col] == '0' || vis[row][col]) return;

            vis[row][col] = true;

            for(auto t : dirs){
                int new_r = row + t[0];
                int new_c = col + t[1]; 

                bfs(new_r,new_c);
            }
        };

        for(int i = 0; i<rows;i++){
            for(int j = 0; j<cols; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    count++;
                    bfs(i,j);
                }
            }
        }

        return count;
    }
};