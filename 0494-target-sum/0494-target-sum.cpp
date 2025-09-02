class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int size = nums.size();
        int dp[21][2001];
        memset(dp , -1 , sizeof(dp));

        function<int(int , int)> call = [&](int index, int sum)->int{
            if(index >= size){
                return target == sum;
            }

            if(dp[index][sum+1000] != -1) return dp[index][sum+1000];

            return dp[index][sum+1000] = call(index+1 , sum - nums[index]) + call(index+1, sum + nums[index]);
        };


        return call(0,0);
    }
};