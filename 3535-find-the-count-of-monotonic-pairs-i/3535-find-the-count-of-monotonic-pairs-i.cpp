class Solution {
public:
    int dp[2001][51][51];

    long solve(int index, vector<int> & nums, int low , int high){
        if(index >= nums.size()){
            return 1;
        }

        if(dp[index][low][high] != -1) return dp[index][low][high];

        long res = 0 ;

        int i = low , j = min(nums[index] , high);

        while( i <= 50 && j >= 0){
            int sum = i+j;

            if(sum == nums[index]){
                res = (res + solve(index+1,nums, i,j)) % 1000000007;
                i++;
                j--;
            }
            else if(sum > nums[index]){
                j--;
            }
            else{
                i++;
            }
        }
        return dp[index][low][high] = res;
    }

    int countOfPairs(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));

        return (int)solve(0 , nums, 0, 50);    
    }
};