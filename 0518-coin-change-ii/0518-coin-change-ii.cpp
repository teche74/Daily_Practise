class Solution {
public:
    int dp[301][50001];
    int solve(int index, vector<int> & coins , int value){
        if(value == 0){
            return 1;
        }
        if(index >= coins.size()){
            return 0;
        }

        if(dp[index][value] != -1) return dp[index][value];
        int take =0;
        
        if(coins[index] <= value) take = solve(index,coins, value- coins[index]);

        int not_take = solve(index+1, coins, value);

        return dp[index][value] = take + not_take;

    }
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return solve(0 , coins, amount);
    }
};