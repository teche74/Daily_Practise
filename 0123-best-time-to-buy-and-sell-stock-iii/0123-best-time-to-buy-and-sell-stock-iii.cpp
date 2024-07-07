class Solution {
public:
    unordered_map<int,unordered_map<int,int>>dp;
    int solve(int index, vector<int>&prices, int action){
        if(index >= prices.size() || action == 0)
        {
            return 0;
        }

        if(dp[index].count(action)) return dp[index][action];

        int take =  0, not_take = 0;

        if(!(action & 1)){
            take = -prices[index] + solve(index+1,prices, action-1);
        }
        else{
            take =  prices[index] + solve(index+1,prices,action-1);
        }
        not_take = solve(index+1,prices, action);

        return dp[index][action] = max(take, not_take);
    }
    int maxProfit(vector<int>& prices) {
        return solve(0,prices,4);
    }
};