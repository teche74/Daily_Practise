class Solution {
public:
    int dp[1002];
    int solve(int index, vector<int> & cost){
        if(index >= cost.size()){
            return 0;
        }

        if(dp[index] != -1) return dp[index];

        int take1_step = 1e9;
        int take2_step = 1e9;

        take1_step = cost[index] + solve(index+1, cost);
        take2_step = cost[index] + solve(index+2,cost);

        return dp[index] = min(take1_step , take2_step);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp,-1,sizeof(dp));
        return min( solve(0,cost) , solve(1, cost));
    }
};