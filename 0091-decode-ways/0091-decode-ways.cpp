class Solution {
public:
    int dp[101];
    int solve(int index, const string & s){
        if(index >= s.size()){
            return 1;
        }


        if(s[index] == '0') return 0;
        if(dp[index] != -1) return dp[index];

        int one_dig = 0 , two_dig =0;

        if(index+1 < s.size()){
            string ptr = s.substr(index,2);
            if(stoi(ptr) <= 26 && stoi(ptr) >= 10){
                two_dig  = solve(index+2,s);
            }
        }

        one_dig = solve(index+1,s);

        return dp[index] = one_dig + two_dig;
    }
    int numDecodings(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
    }
};