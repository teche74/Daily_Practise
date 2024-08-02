class Solution {
public:
    int dp[301][5001];
    int solve(int index , vector<int> & coins , int val){
        if(val == 0) return 1;
        if(index >= coins.size() || val < 0){
            return 0;
        }

        if(dp[index][val] != -1) return dp[index][val];

        int take =  0, not_take = 0;

        if(coins[index] <= val){
            take = solve(index ,coins, val - coins[index]);
        }
        not_take = solve(index+1,coins,val);

        return dp[index][val] =  take + not_take;
    }
    int change(int amount, vector<int>& coins) {
        memset(dp,-1,sizeof(dp));
        return solve(0,coins , amount);
    }
};