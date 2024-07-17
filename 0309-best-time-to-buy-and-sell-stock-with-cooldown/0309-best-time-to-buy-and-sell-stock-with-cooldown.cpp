class Solution {
public:
    int dp[5002][4500];
    int solve(int index, vector<int> & prices, int actions){
        if(index >= prices.size() ){
            return 0;
        }

        if(dp[index][actions] != -1) return dp[index][actions];

        int take = 0 , not_take = 0;


        if(actions){
            take = -prices[index] + solve(index+1,prices,!actions);
        }
        
        if(!actions){
            take = prices[index] + solve(index+2,prices,!actions);
        }

        not_take = solve(index+1,prices,actions);

        return dp[index][actions] = max(take,not_take);
    }
    int maxProfit(vector<int>& prices) {
        int size = prices.size();

        int actions  = size;

        memset(dp, -1, sizeof(dp));

        return solve(0,prices, true);
    }
};