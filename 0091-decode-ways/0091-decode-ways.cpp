class Solution {
public:
    int dp[101];
    int solve(int index, const string  & s){
        if(index >= s.size()){
            return 1;
        }

        if(s[index] == '0') return 0;

        if(dp[index] != -1){
            return dp[index];
        }

        int single_digit = 0, double_digit = 0;

        single_digit = solve(index+1,s);

        if(index+1 < s.size()){
            string str = s.substr(index,2);
            if(str >= "1" && str <= "26"){
                double_digit = solve(index+2,s);
            }
        }

        return dp[index] = single_digit + double_digit; 
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0 , s);
    }
};