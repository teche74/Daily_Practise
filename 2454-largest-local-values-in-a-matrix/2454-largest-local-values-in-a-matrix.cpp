class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int rows = grid.size() ,cols = grid[0].size();

        vector<vector<int>>res;

        vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};


        function<int(int,int)> dfs = [&](int row, int col){
            int val = grid[row][col];

            for(auto t : dirs){
                int new_r = t[0] + row;
                int new_c = t[1] + col;

                if(new_r >= 0 && new_r < rows && new_c >= 0 && new_c < cols ){
                    val = max(val, grid[new_r][new_c]);
                }
            }
            return val;
        };

        for(int i = 1 ;i <rows-1 ;i++){
            vector<int>temp;
            for(int j =1; j< cols-1 ;j++){
                int val = dfs(i,j);
                temp.emplace_back(val);
            }
            res.emplace_back(temp);
        }

        return res;
    }
};