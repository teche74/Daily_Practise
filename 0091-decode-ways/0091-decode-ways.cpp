class Solution {
public:
    // int dp[101];
    // int solve(int index, const string  & s){
    //     if(index >= s.size()){
    //         return 1;
    //     }

    //     if(s[index] == '0') return 0;

    //     if(dp[index] != -1){
    //         return dp[index];
    //     }

    //     int single_digit = 0, double_digit = 0;

    //     single_digit = solve(index+1,s);

    //     if(index+1 < s.size()){
    //         string str = s.substr(index,2);
    //         if(str >= "1" && str <= "26"){
    //             double_digit = solve(index+2,s);
    //         }
    //     }
    //     return dp[index] = single_digit + double_digit; 
    // }
    int numDecodings(string s) {
        // memset(dp,-1,sizeof(dp));
        // return solve(0 , s);

        int size = s.size();

        int dp[size+1];
        memset(dp,0,sizeof(dp));

        dp[size] = 1;

        for(int i =size-1; i >= 0 ;i--){
            if(s[i] == '0'){
                dp[i] = 0;
            }
            else{
                dp[i] = dp[i+1];
                if ( i+1 < size && (s[i] == '1' || s[i] == '2'  && s[i+1] <= '6' )){
                    dp[i] += dp[i+2];
                }
            }
        }

        return dp[0];
    }
};