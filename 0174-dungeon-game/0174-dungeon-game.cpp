class Solution {
public:
    int solve(int i , int j , vector<vector<int>> & arr, vector<vector<int>> &dp){
        if( i >= arr.size() || j >= arr[0].size() ) return INT_MAX;

        if(i == arr.size()-1 && j == arr[0].size()-1) return max(1 , 1 - arr[i][j]);

        if(dp[i][j] != -1) return dp[i][j];

        int left = solve(i+1,j , arr,dp);
        int right = solve(i, j+1,arr,dp);

        int choice = min(left,right);

        return dp[i][j] = max(1, choice - arr[i][j]);
    }
    int calculateMinimumHP(vector<vector<int>>& arr) {
        int rows = arr.size(), cols = arr[0].size();

        vector<vector<int>>dp(rows, vector<int>(cols,-1));

        return max(1 , solve(0,0,arr,dp));
    }
};