class Solution {
public:
    int dp[40009][4];
    int solve(int index , vector<int> & nums, int sum){
        if(index >= nums.size()){
            if( sum == 0 ) return 0;
            return INT_MIN;
        }

        if(dp[index][sum] != -1) return dp[index][sum];

        int take = nums[index] + solve(index +1, nums, (sum + nums[index]) % 3);

        int not_take = solve(index + 1, nums, sum);


        return dp[index][sum] = max(take, not_take);  
    }
    int maxSumDivThree(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, 0);
    }
};