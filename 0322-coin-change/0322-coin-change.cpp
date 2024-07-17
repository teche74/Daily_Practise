class Solution {
public:
    int dp[13][10004];
    int solve(int index, vector<int> & coins , int value){
        if(value == 0 ) return 0;

        if(index >= coins.size()){
            return 1e9;
        }

        if(dp[index][value] != -1) return dp[index][value];

        int take = 1e9 , not_take = 1e9;

        if(coins[index] <= value){
            take = 1 + solve(index,coins,value-coins[index]); 
        }
        not_take = solve(index+1,coins, value);

        return dp[index][value] = min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int res = solve(0 , coins, amount);

        return res == 1e9 ? -1 : res;
    }
};