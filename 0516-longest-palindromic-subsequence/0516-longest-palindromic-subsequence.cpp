class Solution {
public:
    int dp[1001][1001];
    int solve(const string  & s, int low, int high){
        if(low > high) return 0;
        if(low == high ) return 1;

        if(dp[low][high] != -1) return dp[low][high];

        if(s[low] == s[high]){
            return dp[low][high] = 2 + solve(s, low+1, high -1);
        }
        else{
            return dp[low][high] = max(solve(s, low+1, high) , solve(s, low, high-1));
        }
    }
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, size-1);
    }
};