class Solution {
public:
    int dp[13][10001];
    int solve(int index, vector<int>& coins , int total){
        if(total == 0) return 0;
        if(index >= coins.size() || total < 0) return INT_MAX;

        if(dp[index][total] != -1) return dp[index][total];

        int take = INT_MAX , not_take = INT_MAX;
        if(coins[index] <= total){
            int res = solve(index, coins ,total- coins[index]);

            if(res != INT_MAX){
                take = res+1;
            }
        }
        not_take = solve(index+1 , coins , total);

        return dp[index][total] = min(take, not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        int res = solve(0, coins, amount);
        return res == INT_MAX ? -1 : res;
    }
};