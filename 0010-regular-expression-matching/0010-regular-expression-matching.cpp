class Solution {
public:
    bool isMatch(string s, string p) {
        int size1 = s.size() ,  size2 = p.size();

        int dp[21][21];

        memset(dp , 0 , sizeof(dp));

        dp[0][0] = 1;

        for(int i = 1; i <= size1 ; i++){
            dp[i][0] = false;
        }

        for(int j = 1; j <= size2 ; j++){
            if(p[j-1] == '*'){
                dp[0][j] = dp[0][j-2];
            }
        }

        for(int i= 1; i <= size1 ; i++){
            for(int j = 1 ; j <= size2 ; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '.'){
                    dp[i][j] = dp[i-1][j-1];
                }

                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2];

                    if(s[i-1] == p[j-2] || p[j-2] == '.'){
                        dp[i][j] |= dp[i-1][j];
                    } 
                }
            }
        }

        return dp[size1][size2];
    }
};