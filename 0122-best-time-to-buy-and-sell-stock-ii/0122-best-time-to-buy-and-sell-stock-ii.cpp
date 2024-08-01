class Solution {
public:
    int dp[30002][2];
    int solve(int index, vector<int> & prices, bool action){
        if(index >= prices.size()){
            return 0;
        }

        if(dp[index][action] != -1) return dp[index][action];

        int take = 0 , not_take = 0 ;
        if(action){
            take = -prices[index] + max(solve(index,prices,!action),solve(index+1,prices,!action));
        }
        if(!action){
            take= prices[index] + solve(index +1,prices,!action); 
        }

        not_take= solve(index+1,prices,action);

        return dp[index][action] = max(take,not_take); 
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(0,prices,true);
    }
};