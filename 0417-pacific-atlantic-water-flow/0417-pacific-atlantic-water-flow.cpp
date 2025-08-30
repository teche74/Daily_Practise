class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& island) {
        int rows = island.size() , cols = island[0].size();
        vector<pair<int,int>> dirs = {{0,1} , {1,0} , {0,-1} , {-1,0}};
        vector<vector<bool>>pacific(rows, vector<bool>(cols ,false));
        vector<vector<bool>>atlantic(rows, vector<bool>(cols ,false));

        function<void(int,int , vector<vector<bool>> & )>dfs = [&](int row,int col , vector<vector<bool>> & vis){
            vis[row][col] = true;

            for(auto dir_pair : dirs){
                int new_row = row + dir_pair.first;
                int new_col = col + dir_pair.second;
                
                if(new_row >= rows || new_col >= cols || new_row < 0 || new_col < 0 || vis[new_row][new_col] || island[row][col] > island[new_row][new_col]) continue;
                dfs(new_row,new_col,vis);
            }
        };

        for(int row = 0  ; row < rows ; row++){
            dfs(row,0 , pacific);
            dfs(row , cols-1 , atlantic);
        }

        for(int col = 0 ; col < cols ; col++){
            dfs(0 ,col, pacific);
            dfs(rows-1,col , atlantic);
        }


        // till now we have find all valid paths available.
        vector<vector<int>> res;
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j  < cols ; j++){
                if(pacific[i][j] && atlantic[i][j]){
                    res.push_back({i,j});
                }
            }
        }

        return res;
    }
};