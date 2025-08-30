#define loop(integer, start, end) for(int integer  = start ; integer < end ; integer++)

class Solution {
public:
    int numIslands(vector<vector<char>> grid) {
        int rows = grid.size() , cols = grid[0].size();

        function<void(int,int)> bfs = [&](int row , int col){
            grid[row][col] = '2';

            for(auto dir : vector<pair<int,int>>{{0,1} , {1,0} , {0,-1} , {-1,0}}){
                int new_row = row + dir.first;
                int new_col = col + dir.second;

                if(new_row < 0 || new_row >= rows || new_col < 0|| new_col >= cols || grid[new_row][new_col] == '0' || grid[new_row][new_col] == '2') continue;

                bfs(new_row, new_col);
            }
        };

        int islands = 0;

        loop(i,0,rows){
            loop(j,0,cols){
                if(grid[i][j] == '1'){
                    bfs(i,j);
                    islands++;
                }
            }
        }

        return islands;
    }
};