class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[301][5001];

        memset(dp , -1, sizeof(dp));

        function<int(int, int)> solve = [&](int index, int amount){
            if(amount < 0 ) return 0;
            if(index >=  coins.size()){
                if(amount == 0) return 1;
                return 0;
            }

            if(dp[index][amount] != -1) return dp[index][amount];

            int take =0 , not_take = 0;
            
            if(coins[index] <= amount)
            {
                take = solve(index , amount - coins[index]);
            }
            not_take = solve(index+1,amount);

            return dp[index][amount] = take + not_take; 
        };


        return solve(0 , amount );
    }
};