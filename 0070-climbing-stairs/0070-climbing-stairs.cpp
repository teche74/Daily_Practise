class Solution {
public:
    int dp[46];
    
    int solve(int val){
        if(val < 0){
            return 0;
        }

        if(val == 0 ){
            return 1;
        }

        if(dp[val] != -1) return dp[val];

        return dp[val] = solve(val-1) + solve(val-2);
    }
    int climbStairs(int n) {
        memset(dp , -1 , sizeof(dp));

        return solve(n);
    }
};