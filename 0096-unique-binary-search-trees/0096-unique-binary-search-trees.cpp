class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        memset(dp,0,sizeof(dp));

        dp[0] = 1;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            for(int left = 0; left < i ; left++){
                int right =  i -left-1;

                dp[i] += dp[left] * dp[right];
            }
        }
        return dp[n];
    }
};