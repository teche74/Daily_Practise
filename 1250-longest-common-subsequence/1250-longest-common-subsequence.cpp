class Solution {
public:
    int dp[10001][1001];
    int solve(int ind1 , int ind2 , const string  & str , const string & ptr){
        if(ind1  == str.size() || ind2 == ptr.size()){
            return 0;
        }

        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

        int take = 0 , not_take = 0 ,not_take2;

        if(str[ind1] == ptr[ind2]){
            take = 1 + solve(ind1 + 1 ,ind2 + 1 , str, ptr);
        }
        not_take = solve(ind1 + 1 , ind2,str,ptr);
        not_take2 = solve(ind1 ,ind2+1,str,ptr);

        return dp[ind1][ind2] = max({take,not_take, not_take2});
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,text1,text2);
    }
};