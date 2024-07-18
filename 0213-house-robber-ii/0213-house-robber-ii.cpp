class Solution {
public:
    int dp[101][2];
    int solve(int index , vector<int> & nums, bool take_first){
        if(index >= nums.size()){
            return 0;
        }

        if(dp[index][take_first] != -1 ) return dp[index][take_first];

        int take = 0 , not_take = 0;

        if(index == 0 ){
            take = nums[index] + solve(index+2 , nums, true);
            not_take = solve(index+1,nums, false);
        }
        else{
            if(index == nums.size()-1 && take_first){
               take = 0;
            }
            else{
                take = nums[index] + solve(index+2,nums,take_first);
            }
            not_take = solve(index+1,nums,take_first); 
        }

        return dp[index][take_first] = max(take, not_take);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0, nums, false);
    }
};