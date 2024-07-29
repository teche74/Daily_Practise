class Solution {
public:
    bool winnerSquareGame(int n) {
        // bool player = true;
        // int dp[100001];
        // memset(dp , -1 , sizeof(dp));

        // function<bool(int)> solve = [&](int n ){
        //     if(n == 0 ) return false;

        //     if(dp[n] != -1) return (dp[n] == 1);

        //     for(int  i= 1; i * i <= n ; i++ ){
        //         if(!solve(n - i*i)){
        //             dp[n] = 1;
        //             return true;
        //         }
        //     }

        //     dp[n] = 0;
        //     return false;
        // };
        // return solve(n);

        bool dp[n+1];
        memset(dp , false, sizeof(dp));

        for(int i =1 ;i <= n ; i++){
            for(int j = 1; j*j <= i; j++){
                if(!dp[i - j*j]){
                    dp[i ] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};