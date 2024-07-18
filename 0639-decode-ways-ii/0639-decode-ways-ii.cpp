class Solution {
public:
    const int MOD = 1e9 +7;
    int numDecodings(string s) {
        int size = s.size();

        long long dp[size+1];

        memset(dp, 0, sizeof(dp));
        dp[size] =1;

         for (int i = size - 1; i >= 0; --i) {
            if (s[i] == '0') {
                dp[i] = 0;
            } else if (s[i] == '*') {
                dp[i] = 9 * dp[i + 1] % MOD; // '*' : '1'-'9'

                if (i + 1 < size && s[i + 1] == '*') {
                    dp[i] = (dp[i] + 15 * dp[i + 2] % MOD) % MOD; // "**" : 11-19 and 21-26
                } 
                else if (i + 1 < size && s[i + 1] >= '0' && s[i + 1] <= '6') {
                    dp[i] = (dp[i] + 2 * dp[i + 2] % MOD) % MOD; // "*0-6" : 10-16 and 20-26
                } 
                else if (i + 1 < size && s[i + 1] > '6') {
                    dp[i] = (dp[i] + dp[i + 2]) % MOD; // "*7-9"  : 17-19
                }
            } 
            else {
                dp[i] = dp[i + 1]; // single digit 

                if (i + 1 < size && s[i + 1] == '*') {
                    if (s[i] == '1') {
                        dp[i] = (dp[i] + 9 * dp[i + 2] % MOD) % MOD; // "1*" : 11-19
                    } 
                    else if (s[i] == '2') {
                        dp[i] = (dp[i] + 6 * dp[i + 2] % MOD) % MOD; // "2*" : 21-26
                    }
                } 
                else if (i + 1 < size && s[i] == '1') {
                    dp[i] = (dp[i] + dp[i + 2]) % MOD; // "10-19"
                }
                 else if (i + 1 < size && s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6') {
                    dp[i] = (dp[i] + dp[i + 2]) % MOD; // "20-26"
                }
            }
        }

        return dp[0];
    }
};