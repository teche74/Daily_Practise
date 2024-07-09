class Solution {
public:
    int dp[2503][2503];
    int solve(int index, vector<int>& nums, int prev){
        if(index > nums.size()){
            return 0;
        }

        if(dp[index][prev] != -1) return dp[index][prev];

        int take = 0 , not_take = 0;

        if(prev == 0 || nums[prev-1] < nums[index-1]){
            take = 1 + solve(index+1,nums,index);
        }
        not_take = solve(index+1,nums,prev);

        return dp[index][prev] = max(take,not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(1, nums, 0);
    }
};