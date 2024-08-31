class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];

        memset(dp ,0 ,sizeof(dp));

        dp[0] = 1;
        dp[1] = 1;

        for(int nodes = 2; nodes <= n ; nodes++){
            for(int left = 0 ;left < nodes ; left++){
                int right = nodes - left-1;

                dp[nodes] += dp[left] * dp[right]; 
            }
        }

        return dp[n];
    }
};