class Solution {
public:
    int solve(int index, const string & s, vector<int> &dp){
        if(index >= s.size()){
            return 1;
        }

        if(s[index] == '0') return 0;
        if(dp[index] != -1) return dp[index];


        int single_digit = solve(index+1,s,dp);
        int double_digit = 0;

        if(index+1 < s.size() && stoi(s.substr(index,2)) <= 26){
            double_digit = solve(index+2 ,s,dp);
        }

        return dp[index] = single_digit + double_digit;
    }
    int numDecodings(string s) {
        int size = s.size();
        vector<int>dp(size,-1);
        return solve(0,s,dp);
    }
};