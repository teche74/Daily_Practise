class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        vector<vector<int>>cols;

        int size = grid[0].size();

        for(int j= 0;j <size ; j++){
            vector<int>temp;
            for(int i =0; i < grid.size(); i++){
                temp.emplace_back(grid[i][j]);
            }
            cols.emplace_back(temp);
        }

        int count  = 0;

        for(auto  x : grid){
            for(auto y : cols){
                if(x==y) count++;
            }
        }
        return count;
    }
};