//  recursive - > {TLE}

// class Solution {
// public:
//     int solve(int index , vector<int> & prices, int action){
//         if(index >= prices.size() || action == 0){
//             return 0;
//         }

//         int action1 = 0, action2 = 0;

//         if( !(action & 1) ){ // buy ka he
//             action1 += -prices[index]  + solve(index+1,prices, action-1);
//         }
//         else{ // sell ka he
//             action1 += prices[index] + solve(index+1,prices,action-1); 
//         }

//         // state leave kr do (no action).
//         action2+=solve(index+1,prices,action);
        
//         return max(action1,action2);
//     }
//     int maxProfit(vector<int>& prices) {

//         return solve(0 , prices, 2);        
//     }
// };

// memoization

class Solution {
public:

    int solve(int index , vector<int> & prices, int action, int dp[][3]){
        if(index >= prices.size() || action == 0){
            return 0;
        }

        if(dp[index][action] != -1) return dp[index][action];

        int action1 = 0, action2 = 0;

        if( !(action & 1) ){ // buy ka he
            action1 += -prices[index]  + solve(index+1,prices, action-1, dp);
        }
        else{ // sell ka he
            action1 += prices[index] + solve(index+1,prices,action-1,dp); 
        }

        // state leave kr do (no action).
        action2+=solve(index+1,prices,action,dp);
        
        return dp[index][action] = max(action1,action2);
    }
    int maxProfit(vector<int>& prices) {
        int dp[100007][3];
        memset(dp,-1,sizeof(dp));
        return solve(0 , prices, 2, dp);        
    }
};