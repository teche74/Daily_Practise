class Solution {
public:
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int dp[m+1][n+1];

        memset(dp,  0 ,sizeof(dp));


        for(const string str  : strs){
            int z = 0, o = 0;

            for(char ch : str){
                z  += (ch == '0');
                o  += (ch == '1');
            }

            for(int i = m ;i >= z ;i--){
                for(int j = n ;j >= o ;j--){
                    dp[i][j] = max(dp[i][j] , dp[i - z][j - o] + 1);
                }
            }
        }

        return dp[m][n];
    }
};