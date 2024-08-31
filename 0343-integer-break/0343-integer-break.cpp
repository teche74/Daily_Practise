class Solution {
public:
    int dp[58];
    int solve(int val, int count){
        if(val == 0 && count > 1) return 1;
        if(val < 0 ) return 0;

        if(dp[val] != -1) return dp[val];

        int res = 1;

        for(int i =1 ; i <= val ; i++){
            int t  = i  * solve(val -i,count+1);
            // if(count > 1)
            res = max(res,t);
        }

        return dp[val] = res;
    }
    int integerBreak(int n) {
        // memset(dp, -1, sizeof(dp));
        // return solve(n, 0);

        if (n <= 3) return n - 1;

        int product = 1;
        while (n > 4) {
            product *= 3;
            n -= 3;
        }
        
        return product * n;
    }
};