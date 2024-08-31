class Solution {
public:
    int dp[13][10004];
    int solve(int index , vector<int> & coins , int amount){ 
        if(amount == 0 ) return 0;
        
        if(index >= coins.size() || amount < 0){
            return 1e9;
        }

        if(dp[index][amount] != -1) return dp[index][amount];

        int take =  0 , not_take = 0;


        take = 1 + solve(index , coins,amount - coins[index]);
    

        not_take = solve(index + 1, coins , amount);


        return dp[index][amount] = min(take , not_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp , -1,sizeof(dp));

        int val = solve(0, coins , amount);

        if(val == 1e9) return -1;
        return val;
    }
};