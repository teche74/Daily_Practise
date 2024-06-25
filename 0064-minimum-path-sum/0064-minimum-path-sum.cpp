class Solution {
public:
    int solve(int row, int col, vector<vector<int>>&arr, vector<vector<int>> &memo){
        if(row >= arr.size() || col >= arr[0].size()){
            return INT_MAX;
        }

        if(memo[row][col] != -1){
            return memo[row][col];
        }

        if(row == arr.size()-1 && col == arr[0].size()-1){
            return arr[row][col];
        }

        int down = solve(row+1,col,arr, memo);
        int right = solve(row, col+1,arr, memo);

        return memo[row][col] = arr[row][col] + min(down,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>>memo(rows, vector<int>(cols,-1));
        return solve(0,0,grid,memo);
    }
};