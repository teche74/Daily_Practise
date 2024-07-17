class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 1 || n== 0) return pow(10,n); 
        int dp[n+1] ;
        memset(dp , 0, sizeof(dp));

        dp[0] = 1;
        dp[1] = 9;

        int digits =9;

        for(int i = 2; i <=n ;i++){
            dp[i] = dp[i-1] * digits--;
        }

        int sum = 0;

        for(int i = 0 ;i <= n ;i++){
            sum+=dp[i];
        }
        return sum;
    }
};