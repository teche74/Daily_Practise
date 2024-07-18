class Solution {
public:
const int MOD = 1e9 + 7;
    int dp[100001][2][3];
    int solve(int curr, int size , int abs, int late){
        if(curr == size){
            return 1; 
        }

        if(dp[curr][abs][late] != -1) return dp[curr][abs][late] % MOD;

        int absent = 0 , lt = 0 , present = 0; 

        if(abs > 0){
            absent  = solve(curr+1,size,abs-1,2) % MOD;
        }
        if(late > 0){
            lt = solve(curr+1,size,abs,late-1) % MOD;
        }
        present = solve(curr+1,size,abs,2) % MOD;

        return dp[curr][abs][late] = ((absent + lt) % MOD + present) % MOD;
    }
    int checkRecord(int n) {
        int abs = 1;
        int late = 2;
        memset(dp,-1,sizeof(dp));

        return solve(0,n,abs,late);
    }
};