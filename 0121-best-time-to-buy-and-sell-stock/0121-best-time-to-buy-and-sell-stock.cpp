class Solution {
public:
    int dp[100000][3];

    int solve(int index, vector<int> & prices ,  int action){
        if(index >= prices.size() || action == 0){
            return  0;
        }

        if(dp[index][action] != -1) return dp[index][action];

        int buy =  0 , leave = 0;
        
        leave = solve(index+1,prices, action);

        if(!(action & 1)){
            buy = -prices[index] + solve(index + 1, prices, action-1);
        }

        if(action & 1){
            buy = prices[index] + solve(index + 1 , prices , action-1);
        }

        return dp[index][action] = max(buy ,leave);
    }

    int maxProfit(vector<int>& prices) {
        memset(dp , -1, sizeof(dp));
        return solve( 0 ,prices, 2);    
    }
};