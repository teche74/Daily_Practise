class Solution {
public:
    int solve(int index, vector<int>& coins, int amount, vector<vector<int>>&dp){
        if(amount == 0) return 0;

        if(index >= coins.size()) return INT_MAX;

        if(dp[index][amount] != -1) return dp[index][amount];

        int take = INT_MAX;
        if(coins[index] <= amount){
            int res = solve(index,coins, amount - coins[index],dp);
            if(res != INT_MAX){
                take = res+1;
            }
        }

        int not_take = solve(index+1,coins , amount,dp);

        return dp[index][amount] = min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(13,vector<int>(1e5,-1));
        int res = solve(0, coins, amount,dp);
        return  res == INT_MAX ? -1 : res ;
    }
};