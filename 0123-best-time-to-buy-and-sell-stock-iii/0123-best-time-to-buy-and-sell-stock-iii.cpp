class Solution {
public:
    int solve(vector<int> & arr, int index, int moves,vector<vector<int>> &dp){
        if(index  ==  arr.size()){
            return 0;
        }

        if(moves == 0){
            return 0;
        }


        if(dp[index][moves] != -1) return dp[index][moves]; 

        int take = 0;

        if( !(moves & 1) ){
            take = -arr[index] + solve(arr,index+1, moves-1,dp);
        }
        else{
            take  = arr[index] + solve(arr,index+1,moves-1,dp); 
        }

        int not_take = solve(arr,index+1,moves,dp);

        dp[index][moves] = max(take, not_take);

        return dp[index][moves];
    }
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<vector<int>>dp(size, vector<int>(5, -1));
        return solve(prices, 0, 4,dp);
    }
};