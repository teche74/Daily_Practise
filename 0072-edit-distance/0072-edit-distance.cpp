class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int dp[501][501];

        function<int(int,int)>solve = [&](int i , int j){
            if(i == m){
                return n - j;
            }
            if(j == n){
                return m - i;
            }

            if(dp[i][j] != -1) return dp[i][j];

            int no_oper = INT_MAX;
            if(word1[i] == word2[j]){
                no_oper = solve(i+1,j+1);
            }
            int insert = 1 + solve(i,j+1);
            int del  = 1 + solve(i+1,j);
            int replace =1 + solve(i+1,j+1);

            return dp[i][j] = min({insert,del,replace, no_oper});
        };
        memset(dp,-1,sizeof(dp));
        return solve(0,0);
    };
};