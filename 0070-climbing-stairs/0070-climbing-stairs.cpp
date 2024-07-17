class Solution {
public:
    int dp[46];
    int solve(int curr){
        if(curr == 0){
            return 1;
        }

        if(dp[curr] != -1) return dp[curr];


        int take = solve(curr-1);

        int take_2 =0;
        
        if(curr >=2)
            take_2 = solve(curr-2);

        return dp[curr] = take + take_2;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};