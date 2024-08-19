class Solution {
public:
    int dp[101];
    int solve(int index, string & str){
        if(index >= str.size()){
            return 1;
        }

        if(str[index] == '0') return 0;

        if(dp[index] != -1) return dp[index];

        int single = solve(index+1,str);

        int doub = 0;

        if(index + 1 < str.size() && str.substr(index,2) <= "26"){
            doub = solve(index+2 , str);
        }

        return dp[index] = single + doub;
    }
    int numDecodings(string s) {
        memset(dp , -1 ,sizeof(dp));
        return solve(0 ,s);
    }
};