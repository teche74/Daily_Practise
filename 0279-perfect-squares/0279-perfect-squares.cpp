class Solution {
public:
    int dp[10004];

    int solve(int val){
        if(val <= 0){
            return 0;
        }

        if(dp[val] != -1) return dp[val];

        int count =INT_MAX;

        for(int i = 1 ; i *  i <= val ; i++){
            int t =1 + solve(val - (i * i));
            count  = min(count , t);
        }
        return dp[val] = count;
    }
   
    int numSquares(int n) {
        memset(dp , -1,sizeof(dp));

        return solve(n);
    }
};