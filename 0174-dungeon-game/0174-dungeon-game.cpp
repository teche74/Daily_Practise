class Solution {
public:
    int solve(int row, int col , int rows, int cols, vector<vector<int>>arr,vector<vector<int>> & dp){

        if(row >= rows || col >= cols ) return  INT_MAX; 

        if(row == rows-1  && col == cols-1 ){
            return max(1,1 - arr[row][col]);
        }


        if(dp[row][col] != -1) return dp[row][col];


        int take_right = solve(row+1,col,rows,cols,arr,dp);

        int take_down = solve(row,col+1,rows, cols, arr, dp);

        int mini = min(take_right, take_down);


        return dp[row][col] = max(mini - arr[row][col],1);

    }

    int calculateMinimumHP(vector<vector<int>>& arr) {
        int rows = arr.size() , cols = arr[0].size();

        if(rows-1 == 0 && cols -1 == 0 ) return arr[rows-1][cols-1] < 0 ? abs(arr[rows-1][cols-1])+1 : 1;

        vector<vector<int>>dp(rows +1 , vector<int>(cols+1, -1));

        return solve(0,0,rows,cols,arr,dp);
    }
};