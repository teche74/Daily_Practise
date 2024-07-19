class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int dp[size];
        memset(dp,0 ,sizeof(dp));
        dp[0] = nums[0];
        int max_sum = dp[0] ;


        for(int i =1; i < size ; i++){
            dp[i] = max(nums[i], dp[i-1] + nums[i] );
            max_sum = max(max_sum ,dp[i]);
        }

        return max_sum;
    }
};