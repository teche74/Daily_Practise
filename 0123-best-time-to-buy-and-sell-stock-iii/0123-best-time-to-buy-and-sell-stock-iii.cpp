class Solution {
public:
    int dp[100005][5];
    int solve(int index, vector<int> & prices, int actions){
        if(index >= prices.size() || actions == 0){
            return 0;
        }

        if(dp[index][actions]!= -1) return dp[index][actions];

        int take = 0 , leave = 0; 

        if(!(actions  & 1) ){
            take = -prices[index] + solve(index+1,prices,actions-1);
        }
        if(actions & 1){
            take = prices[index] + solve(index+1,prices,actions-1);
        }

        leave = solve(index+1,prices,actions);

        return dp[index][actions] = max(take, leave);
    }
    int maxProfit(vector<int>& prices) {
        int size =prices.size();

        memset(dp, -1, sizeof(dp));

        return solve(0,prices,4);
    }
};