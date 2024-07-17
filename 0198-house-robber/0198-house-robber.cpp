class Solution {
public:
    int dp[101];
    int solve(int index, vector<int> & nums){
        if(index >= nums.size() ){
            return 0;
        }

        if(dp[index] != -1) return dp[index];

        int take = 0 , not_take = 0;

        take = nums[index] + solve(index+2, nums);

        not_take = solve(index+1,nums);

        return dp[index] = max(take, not_take);
    }
    int rob(vector<int>& nums) {
        int size = nums.size();

        memset(dp, -1, sizeof(dp));

        return solve(0, nums);
    }
};