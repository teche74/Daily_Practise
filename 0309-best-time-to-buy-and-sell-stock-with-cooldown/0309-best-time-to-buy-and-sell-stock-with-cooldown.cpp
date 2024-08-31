class Solution {
public:
    int dp[5001][2];

    int solve(int index, vector<int> & prices , bool action){
        if(index >= prices.size()){
            return 0;
        }

        if(dp[index][action] != -1) return dp[index][action];

        int buy = 0 , leave = 0;

        leave = solve(index + 1, prices,action);

        if(action){
            buy = -prices[index] + solve(index+1,prices , !action);
        }
        if(!action){
            buy = prices[index] + solve(index + 2 , prices , !action);
        }

        return dp[index][action] = max(buy , leave);
    }

    int maxProfit(vector<int>& prices) {
        memset(dp , -1, sizeof(dp));
        return solve(0, prices,true);
    }
};