class Solution {
public:
    int dp[1005];

    int solve(int index, vector<int>  & cost){
        if(index >= cost.size()) return 0;

        if(dp[index] != -1) return  dp[index];

        int res = 1e9;

        res = cost[index] + min(solve(index+1, cost) , solve(index+2,cost));

        return dp[index] = res;
    }


    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));
        return min(solve(0, cost) , solve(1, cost));
    }
};