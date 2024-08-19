class Solution {
public:
    int dp[101][101][201];
    bool solve(int i , int j  , int k , string  & str, string & str2 , string & str3){
        if(k == str3.size()) return true;
        if(i >= str.size() && j >= str2.size() ) return false;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        bool take_first = false;
        bool take_second = false;

        if(i < str.size() &&  str[i] == str3[k])
            take_first = solve(i+1, j , k+1 , str,str2 , str3);

        if(j  <str2.size() && str2[j] == str3[k])
            take_second = solve(i , j+1, k+1, str, str2, str3);

        return dp[i][j][k] = take_first || take_second;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()  + s2.size() > s3.size() ) return false;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0,s1,s2,s3);
    }
};