class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size() , cols = grid[0].size();

        queue<pair<pair<int,int>,int>> q;
        int res = 0;


        vector<vector<bool>>vis(rows, vector<bool>(cols, false));

        for(int i = 0; i <rows ; i++){
            for(int j =0; j < cols; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else{
                    vis[i][j] = 0;
                }
            }
        }

        vector<vector<int>>dirs = {{0,1}, {1,0} , {-1,0} , {0,-1}};

        while(!q.empty()){
            int curr_row = q.front().first.first;
            int curr_col = q.front().first.second;
            int time = q.front().second;

            q.pop();

            res = max(res,time);

            for(auto t : dirs){
                int new_r = curr_row + t[0];
                int new_c = curr_col + t[1];


                if(new_r >= 0 && new_r < rows  && new_c >=0 && new_c < cols && !vis[new_r][new_c] && grid[new_r][new_c] == 1){
                    q.push({{new_r,new_c},time+1});
                    vis[new_r][new_c] = true;
                }
            }
        }


        for(int i=0;i<rows;i++){
            for(int j=0;j<cols ;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    return -1;
                }
            }
        }
        
        return res;


    }
};