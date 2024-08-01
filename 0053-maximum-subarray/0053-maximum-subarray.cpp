class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // kadane
        // int sum = 0 , max_sum = INT_MIN;

        // for(int x :  nums){
        //     sum+=x;

        //     if(sum < x){
        //         sum = x;
        //     }

        //     max_sum = max(max_sum , sum);
        // } 

        // return max_sum;


        // prefix map

        int size = nums.size();

        int dp[size+1];
        
        memset(dp, 0 ,sizeof(dp));

        dp[0] = nums[0];

        for(int i = 1; i < size ; i++){
            dp[i] = max( nums[i] , dp[i-1] + nums[i] );
        }

        return *max_element(dp, dp + size);
        
    }
};