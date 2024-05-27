class Solution {
public:
    int solve(int index, vector<int> & arr, int moves, vector<vector<int>> & dp){
        if(index == arr.size()){
            return 0;
        }


        if(!moves) {
            return 0;
        }

        if(dp[index][moves] != -1) return dp[index][moves];

        int take,nottake;
        if( !(moves &1 ) ){
            take = -arr[index] + solve(index+1,arr,moves-1,dp); // khreda 
        }
        else{
            take = arr[index] + solve(index+1,arr,moves-1,dp); // becha
        }

        nottake=  solve(index+1,arr,moves,dp);

        return dp[index][moves] = max(take,nottake);

    }
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>>dp(size, vector<int>(5, -1));
        return solve(0 , prices, 4, dp);
    }
};