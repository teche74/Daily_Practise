class Solution {
public:
    int MOD  = 1000000007; 
    int numDistinct(string s, string t) {
        int  m = s.size() , n = t.size();

        long long dp[m+1][n+1];

        memset(dp, 0 , sizeof(dp));

        // dono khali ke liye 1 subsequence bnega na . 
        dp[0][0] =1;


        // manle agr t khali he tab bhi ek hi condition he ki tu s ko bhhi khali kr tabhi 1 subsequence bnega.
        for(int i =1 ;i <= m; i++ ){
            dp[i][0] =1;
        }


        // abs soch agr s khali hua to kya possible , are ho hi ni skta

        for(int i =1 ;i <= n ; i++){
            dp[0][i] = 0;
        }   


        // age ka karyakram

        for(int i =1; i <= m ;i++){
            for(int j=1; j<= n; j++){

                // me khta agr dono match kr gye
                if(s[i-1] == t[j-1]){
                    // bhai 2 scene he (jhan tak mrko lgta he )
                        // 1 : ab tak jitne bane  +  2 : isvale ko chunkr or jitne bnege
                    
                    //  phle ke jitne bne : dp[i-1][j-1]
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
                }
                else{
                    //  are jab match ni hora to ispe dhyan du kaiko.
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        //  abe easy tha be .
        return dp[m][n];
    }
};