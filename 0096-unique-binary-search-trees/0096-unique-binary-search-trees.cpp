class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1,0);

        dp[0] =1; // 0 nodes me 1 bst posisible he;

        for(int nodes = 1 ; nodes <= n; nodes++){
            
            for(int left = 0; left < nodes ;left++){ // bst me left nodes ki possiblities

                int right = nodes - left - 1; // total me se left ghtaya right milega 

                dp[nodes] += (dp[left] * dp[right]) ; // left right milakr sare combinations.

            }
        }

        return dp[n];
    }
};