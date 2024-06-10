class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int sum = ::accumulate(nums.begin(),nums.end(),0);

        if(sum & 1) return false;

        int half = sum >> 1;

        vector<bool>dp(half+1,false);
        dp[0] = true;

        for(int x : nums){
            for(int i = half ; i >= x ; i--){
                dp[i] = dp[i] || dp[i-x];
            }
        }
        return dp[half];
    }
};