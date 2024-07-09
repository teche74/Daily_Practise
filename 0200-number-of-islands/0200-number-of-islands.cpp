class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size() , cols = grid[0].size();
        vector<vector<bool>>vis(rows, vector<bool>(cols, false));

        vector<vector<int>>dirs = {{1,0}, {0,1} , {-1,0}, {0,-1}};

        function<void(int,int)> dfs = [&](int row, int col){
            vis[row][col] = true;
            for(auto t : dirs){
                int new_r = row + t[0];
                int new_c  = col + t[1];

                if(new_r >= 0 && new_r < rows && new_c >= 0 && new_c <cols && !vis[new_r][new_c] && grid[new_r][new_c] == '1'){
                    dfs(new_r,new_c);
                }
            }
        }; 

        int count = 0;

        for(int i =0; i <rows ; i++){
            for(int j = 0 ; j <cols ; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    count++;
                    dfs(i,j);
                }
            }
        }
        return count;
    }
};