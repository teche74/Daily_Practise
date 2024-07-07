class Solution {
public:
    int solve(int index, vector<int>&prices, int action, vector<vector<int>> &dp){
        if(index >= prices.size() || action == 0)
        {
            return 0;
        }

        if(dp[index][action] != -1) return dp[index][action];

        int take =  0, not_take = 0;

        if(!(action & 1)){
            take = -prices[index] + solve(index+1,prices, action-1,dp);
        }
        else{
            take =  prices[index] + solve(index+1,prices,action-1,dp);
        }
        not_take = solve(index+1,prices, action,dp);

        return dp[index][action] = max(take, not_take);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1,vector<int>(5,-1));
        return solve(0,prices,4,dp);
    }
};