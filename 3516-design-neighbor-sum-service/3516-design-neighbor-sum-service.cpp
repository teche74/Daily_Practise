class neighborSum {
public:
    int diag[11][11],adj[11][11];
    unordered_map<int,pair<int,int>>map;
    
    neighborSum(vector<vector<int>>& grid) {
        int size = grid.size() ;

        memset(diag,0,sizeof(diag));
        memset(adj,0,sizeof(adj));

        function<int(int,int)> sum = [&](int row, int col){
            int left = (row - 1 >= 0) ?  grid[row-1][col] : 0;
            int right = (row + 1  < size) ? grid[row+1][col] :  0;
            int top = (col - 1 >= 0) ? grid[row][col-1] : 0;
            int bottom = (col + 1 < size) ? grid[row][col+1] : 0;

            return left + right + top + bottom;  
        };

        function<int(int,int)> diago = [&](int row, int col){
            int top_left_diag = (row - 1 >= 0 && col- 1 >= 0) ?  grid[row-1][col-1] : 0;
            int top_right_diag = (row - 1 >= 0 && col +1 < size) ? grid[row-1][col+1] :  0;
            int bottom_left_diag = (row + 1 < size && col -1 >= 0) ? grid[row+1][col-1] : 0;
            int bottom_right_diag = (row+1 < size && col + 1 <size) ? grid[row+1][col+1] : 0;

            return top_left_diag + top_right_diag + bottom_left_diag + bottom_right_diag;  
        };

        for(int i = 0; i < size; i ++){
            for(int j = 0; j < size ;j++){
                map[grid[i][j]] = make_pair(i,j);
                diag[i][j] = diago(i,j);
                adj[i][j] = sum(i,j);
            }
        }
    }
    
    int adjacentSum(int value) {
        auto t  = map[value];
        return adj[t.first][t.second]; 
    }
    
    int diagonalSum(int value) {
        auto t = map[value];
        return diag[t.first][t.second];
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */