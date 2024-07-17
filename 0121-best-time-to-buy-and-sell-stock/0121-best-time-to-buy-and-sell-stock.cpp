class Solution {
public:
    int dp[100005][3];
    int solve(int index, vector<int> & prices, int action){
        if(action == 0){
            return 0;
        }
        if(index >= prices.size()){
            return 0;
        }

        if(dp[index][action]  != -1) return dp[index][action];


        int take = 0 , leave =0;

        if(!(action & 1)){
            take += -prices[index] + solve(index+1, prices , action-1);
        }

        if( action & 1 ){
            take += prices[index] + solve(index+1, prices, action-1);
        }

        leave = solve(index+1,prices,action);

        return dp[index][action] = max(take, leave);
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(0, prices, 2);
    }
};