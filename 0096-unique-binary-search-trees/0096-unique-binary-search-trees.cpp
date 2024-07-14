class Solution {
public:
    int numTrees(int n) {
        // if(n == 1 || n == 0) return 1;

        // int res = 0;

        // for(int i =1 ; i<= n; i++){
        //     res += numTrees(i-1) * numTrees(n-i);
        // } 

        // return res;

        int dp[n+1];
        memset(dp, 0 ,sizeof(dp));

        dp[0] = 1 ;

        for(int i =1 ; i<= n; i++){
            for(int left = 0 ; left < i ; left++){
                int right = i - left - 1 ;

                dp[i] += dp[left] * dp[right];
            }
        }
        return dp[n];
    }
};