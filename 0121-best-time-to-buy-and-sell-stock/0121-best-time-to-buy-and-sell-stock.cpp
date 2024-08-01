class Solution {
public:
    int solve(int index , vector<int> & prices, int action , vector<vector<int>> & dp){
        if(index >= prices.size() || action == 0){
            return 0;
        }

        if(dp[index][action] != -1) return dp[index][action];

        int act = 0 , leave = 0;

        leave = solve(index+1,prices,action,dp);
        if(!(action & 1)){
            act += -prices[index] + solve(index+1,prices,action-1,dp);
        }

        if(action & 1){
            act += prices[index] + solve(index+1,prices,action-1,dp);
        }


        return dp[index][action]  = max(act,leave);
    }
    int maxProfit(vector<int>& prices) {
        // vector<vector<int>>dp(prices.size()+1,vector<int>(3,-1));
        // return solve(0,prices,2,dp);

        int size = prices.size();
        int min_price = INT_MAX,res = 0;

        for(int i =0; i  <size; i++){
            min_price = min(prices[i] , min_price);
            res = max(res, prices[i] - min_price);
        }

        return res;
    }
};