class Solution {
public:
    int dp[100005][3];
    int solve(int index, vector<int> & nums, int action){
        if(index >= nums.size() || action == 0){
            return 0;
        }

        if(dp[index][action] != -1) return dp[index][action];

        int take = 0 ;
        
        if( !(action &1) ) take = -nums[index] + solve(index+1,nums, action-1);

        int not_take = 0 ;

        if(action & 1) take  =  nums[index] + solve(index+1,nums,action-1);

        not_take = solve(index+1,nums,action);

        return dp[index][action] = max(take, not_take);        
    }
    int maxProfit(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0 , nums, 2);
    }
};