class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {

        if (s1.size() + s2.size() != s3.size() ) return false;

        int dp[201][201];
        
        function<bool(int,int,int)> solve = [&](int i, int j ,int k){
            if(k == s3.size()) return true;

            if(dp[i][j] != -1){
                return (dp[i][j] == 1);
            }
            bool first = false,second = false;
            
            if(i < s1.size() && s1[i] == s3[k])
                first = solve(i+1,j,k+1);
            
            if(j < s2.size() && s2[j] == s3[k]){
                second = solve(i,j+1,k+1);
            }

            dp[i][j] = first || second;
            return first || second;
        };
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);
    }
};