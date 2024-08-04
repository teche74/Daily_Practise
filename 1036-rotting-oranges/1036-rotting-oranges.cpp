class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size() , cols = grid[0].size(), fresh = 0;

        queue<pair<pair<int,int>,int>>q;
        bool vis[rows][cols];
        memset(vis,false,sizeof(vis));
        

        for(int i = 0 ; i <rows ; i++){
            for(int j = 0; j < cols ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int res = 0;

        vector<vector<int>>dirs = {{0,1},{-1,0} ,{1,0} ,{0,-1}};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time =q.front().second;
            q.pop();

            res = max(res,time);

            for(auto t : dirs){
                int new_r = row + t[0];
                int new_c = col + t[1];

                if(new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols && grid[new_r][new_c] == 1 && !vis[new_r][new_c] ){
                    fresh--;
                    vis[new_r][new_c] = true;
                    q.push({{new_r,new_c},time+1});
                }
            } 
        }

        if(fresh != 0 ) return -1;

        return res;

    }
};