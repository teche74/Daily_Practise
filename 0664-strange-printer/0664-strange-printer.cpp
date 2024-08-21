class Solution {
public:
    int dp[101][101];

    int solve(int low, int high, string &str) {
        if (low > high) return 0; 
        if (low == high) return 1; 
        if (dp[low][high] != -1) return dp[low][high];
        
        int res = solve(low, high - 1, str) + 1; 
        
        for (int k = low; k < high; ++k) {
            if (str[k] == str[high]) {
                res = min(res, solve(low, k, str) + solve(k + 1, high - 1, str));
            }
        }
        
        return dp[low][high] = res;
    }

    int strangePrinter(string s) {
        memset(dp, -1, sizeof(dp));
        int n = s.length();
        return solve(0, n - 1, s);
    }
};
