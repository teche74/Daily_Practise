class Solution {
public:
    int dp[101][101];
    int solve(int sx, int sy, int ex, int ey){
        if(sx == ex-1  && sy == ey-1) return 1;

        if(dp[sx][sy] != -1) return dp[sx][sy];

        if(sx < 0  ||  sx >= ex || sy < 0 || sy >= ey) return 0;

        return dp[sx][sy] = solve(sx+1,sy,ex,ey) + solve(sx , sy+1,ex,ey);

    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m,n);
    }
};