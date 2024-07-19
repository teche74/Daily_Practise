class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int size = *max_element(nums.begin(), nums.end());

        int arr[size+1];

        memset(arr, 0, sizeof(arr));

        for(int x : nums){
            arr[x] += x;
        }


        vector<int>dp(size+1, 0);

        dp[0] = arr[0];
        dp[1] = max(arr[0], arr[1]);


        for(int i= 2; i<= size; i++){
            dp[i] = max(dp[i-1] , arr[i] + dp[i-2]);
        }

        return dp[size]; 
    }
};