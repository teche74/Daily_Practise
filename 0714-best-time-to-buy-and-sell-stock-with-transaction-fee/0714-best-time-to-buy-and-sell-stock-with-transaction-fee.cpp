class Solution {
public:

    // int solve(int index, vector<int> & prices, int actions,  int fees, vector<vector<int>> &dp){
    //     if(index >= prices.size() || actions == 0){
    //         return 0;
    //     }

    //     if(dp[index][actions] != -1) return dp[index][actions];

    //     int take = 0 , leave = 0 ;

    //     if(!(actions & 1)){
    //         take = -prices[index] + solve(index+1,prices, actions-1,fees,dp);
    //     }
    //     if(actions & 1 && prices[index] >= take){
    //         take = -fees + prices[index] + solve(index+1,prices,actions-1,fees,dp);
    //     }

    //     leave = solve(index+1,prices,actions,fees,dp);

    //     return dp[index][actions] = max(take, leave);
    // }

    // int maxProfit(vector<int>& prices, int fee) {
    //     int size = prices.size();
    //     int actions = size;

    //     while(actions & 1)  actions--;
    //     vector<vector<int>>dp(size+1,vector<int>(actions+1,-1));

    //     return solve(0,prices,actions,fee,dp);
    // }

    int maxProfit(vector<int>& prices, int fee) {
        int size = prices.size();
        
        int profit = 0;
        int hold = -prices[0];

        for(int i=1;i < size; i++){
            profit = max(profit,hold + prices[i] - fee);
            hold = max(hold, profit - prices[i]); 
        }

        return profit;
    }
};