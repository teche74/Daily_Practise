class Solution {
public:
    int dp[201][20010];
    bool solve(int index, vector<int> & nums, int sum){
        if(sum == 0) return true;

        if(index >= nums.size()){
            return false;
        }

        if(dp[index][sum] != -1) return dp[index][sum];

        int take= false, not_take =false;

        if(sum - nums[index] >= 0){
            take = solve(index+1,nums, sum-nums[index]);
        }
        not_take = solve(index+1,nums,sum);

        return dp[index][sum] = take | not_take;
    }
    bool canPartition(vector<int>& nums) {
        int sum = ::accumulate(nums.begin(), nums.end(),0);
        int size = nums.size();

        if( sum & 1 ) return false;
        memset(dp,-1,sizeof(dp));

        int half = sum >> 1;

        return solve(0,nums, half);
    }
};